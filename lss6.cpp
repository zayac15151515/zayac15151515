#include <locale.h>  // Для setlocale (LC_ALL, "")
#include <iostream>

#include <mutex>
#include <vector>
#include <thread>
#include <optional>
#include <cmath>
#include <map>
#include <chrono>
#include <random>
#include <iterator>
#include <algorithm>

using namespace std;


static mutex mtx_cout;

// * Asynchronous output
struct pcout
{
private:
    unique_lock <mutex> lk;

public:
    pcout() : lk (unique_lock <mutex> (mtx_cout)) {};//, defer_lock)) {};
    ~pcout() = default;
        
    template<typename T>
    pcout& operator << (const T& _obj) {
        cout << _obj;
        // return
        return *this;
    };

    pcout& operator << (ostream& (*fp)(ostream&)) {
        cout << fp;
        // return
        return *this;
    };
}; // struct pcout


class pBar
{
private:
    mutex mtx_bar;

    int amountOfFiller,
        pBarLength,     // I would recommend NOT changing this
        currUpdateVal;  // Do not change

    double
        currentProgress,// Do not change
        neededProgress; // I would recommend NOT changing this

public:
    const string        // Change these at will (that is why I made them public)
        firstPartOfpBar = "[",
        lastPartOfpBar  = "]",
        pBarFiller      = "|",
        pBarUpdater     = "/-\\|";

    pBar (int _pBarLength = 50) 
    :   pBarLength (_pBarLength), 
        currUpdateVal (0),
        currentProgress (0),
        neededProgress (100)
    {};

    ~pBar () = default;

    double get_currentProgress () {
        return currentProgress;
    };

    void add (const double);

    void update (const double);

    void print ();

}; // class pBar

void pBar::add (const double _value) {
    lock_guard <mutex> guard (mtx_bar);
    currentProgress += _value;
    amountOfFiller  = static_cast <int> ((currentProgress / neededProgress) * static_cast <double> (pBarLength));
}; // pBar::add

void pBar::update (const double _value) {
    lock_guard <mutex> guard (mtx_bar);
    currentProgress = _value;
    amountOfFiller  = static_cast <int> ((currentProgress / neededProgress) * static_cast <double> (pBarLength));
}; // pBar::update

void pBar::print() {
    lock_guard <mutex> guard (mtx_bar);

    currUpdateVal %= pBarUpdater.length();

    pcout _cout{};
    _cout   << "\r" // Bring cursor to start of line
            << firstPartOfpBar; // Print out first part of pBar
    for (int a = 0; a < amountOfFiller; a++) { // Print out current progress
        _cout << pBarFiller;
    }
    _cout   << pBarUpdater[currUpdateVal];
    for (int b = 0; b < pBarLength - amountOfFiller; b++) { // Print out spaces
        _cout << " ";
    }
    _cout   << lastPartOfpBar // Print out last part of progress bar
            << " (" << (int)(100*(currentProgress/neededProgress)) << "%)" // This just prints out the percent
            << flush;
    currUpdateVal += 1;
}; 


class prime
{
private:
    // mutex
    mutex mtx_prime;

    // number && result
    const unsigned long number;
    optional <unsigned long> result;

    unsigned long
        sieveSize, max_i;
    unsigned long findSieveSize();
    unsigned long find_nth_prime();

    // progress bar (if it's needed)
    pBar *bar;

public:
    prime (const unsigned long _n)
    :   number (_n),
        bar (nullptr),
        result (nullopt)
    {
        sieveSize = findSieveSize ();
        max_i     = sqrt (sieveSize-1)+1;
    };

    ~prime () = default;

    void set_pBar (pBar *_bar) {
        bar = _bar;
    };

    unsigned long calc();
};


unsigned long prime::findSieveSize () {

    if (number < 6)
        return 13;

    // We can't find a prime that will exceed ~0UL.
    if (number >= (~0UL / log(~0UL)))
        return 0;

    // Binary search for the right value.
    unsigned long low  = number;
    unsigned long high = ~0UL - 1;
    do {
        unsigned long mid   = low + (high - low) / 2;
        double        guess = mid / log(mid);

        if (guess > number)
            high  = (unsigned long) mid - 1;
        else
            low   = (unsigned long) mid + 1;
    } while (low  < high);
    // return
    return high + 1;
} // prime::findSieveSize

unsigned long prime::find_nth_prime () {
    
    unsigned long
        n       = number,
        count   = 0;

    if (!n)   return 1; // "0th prime"
    if (!--n) return 2; // first prime

    if (sieveSize == 0)
        return 0;

    // the sieve
    vector <bool> sieve (sieveSize);

    // setup progress bar
    const double onePerc = static_cast <double> (n) / 100.0;

    // main for ...
    for (unsigned long i = 3;  true;  i += 2) {

        if (bar) {
            // progress bar
            double totalPerc = round (static_cast <double> (count) / onePerc);
            if (totalPerc > 99.0)
                totalPerc = 99.0;
            // + %
            double deltaBar = totalPerc - bar->get_currentProgress ();
            // refresh rate
            if (deltaBar >= 1.0) {
                bar->update (totalPerc);
                bar->print ();
        
            }
        }
        
        // calc
        if (!sieve[i]) {
            if (++count == n) {
                if (bar) {
                    bar->update (100.0);
                    bar->print ();
                    this_thread::sleep_for (chrono::milliseconds (1));
                }
                // return
                return i;
            }
                
            if (i >= max_i)
                continue;
            unsigned long j    = i * i;
            unsigned long inc  = i + i;
            unsigned long maxj = sieveSize - inc;

            do {
                sieve[j] = true;
                if (j >= maxj)
                    break;
                j += inc;
            } while (1);
        }
    }
    // return
    return 0;
} // prime::find_nth_prime

unsigned long prime::calc () {
    lock_guard <mutex> guard (mtx_prime);
    if (result.has_value())
        return result.value();
    result = find_nth_prime ();
    // return
    return result.value();
} 



class owner
{
private:
    // mutex
    mutex mtx_wallet;
    unique_lock <mutex> lk;

    // wallet
    vector <int> wallet;
    
    // seconds (for «Do» func)
    const size_t TTL;

protected:
    void showWallet () {
        cout << "owner's wallet < ";
        copy (wallet.rbegin(), wallet.rend(), ostream_iterator <int> (cout, " "));
        cout << ">" << endl;
    };

public:
    owner (size_t _TTL = 30)
    :   lk (unique_lock <mutex> (mtx_wallet, defer_lock)),
        TTL (_TTL)
    {};
    ~owner() = default;

    void Do ();

    friend class thief;
}; 

void owner::Do () {

    mt19937 gen {random_device () ()};

    uniform_int_distribution <int> RNG_INT (1, 100);
    // start
    lk.lock();
    cout << "\n[owner] started for " << TTL << " seconds, wallet is empty..." << endl;
    lk.unlock();
    
    for (auto i = 0; i < TTL; ++i) {
        int coin = RNG_INT (gen);
  
        lk.lock ();
        wallet.emplace_back (coin);
        cout << "\n[owner] added the coin <" << coin << "> to the wallet." << endl;
        showWallet ();
        lk.unlock ();
     
        this_thread::sleep_for (chrono::seconds (1));
    }

    lk.lock();
    cout << "\n[owner] stopped." << endl;
    lk.unlock();
} 


class thief
{
private:
    // mutex
    unique_lock <mutex> lk;

    // seconds (for «Do» func)
    const size_t TTL, delay;

    // owner
    owner *victim;

public:
    thief (owner *_owner, size_t _TTL = 30, size_t _delay = 0)
    :   lk (unique_lock <mutex> (_owner->mtx_wallet, defer_lock)),
        victim (_owner),
        TTL (_TTL),
        delay (_delay)
    {};
    ~thief() = default;

    void Do ();

}; // class thief

void thief::Do () {
    // dalay
    this_thread::sleep_for (chrono::seconds (delay));
    // start
    lk.lock();
    cout << "\n[thief] started for " << TTL << " seconds..." << endl;
    lk.unlock();
    // main for ...
    for (auto i = 0; i < TTL * 2; ++i) {

        lk.lock ();
        // check owner's wallet
        if (!victim->wallet.size()) {
            cout << "\n[thief] theft failed(!)" << endl;
            victim->showWallet ();
        } else {
            auto it_coin = max_element (victim->wallet.begin(), victim->wallet.end());
            cout << "\n[thief] stole <" << *it_coin << "> coin." << endl;

            victim->wallet.erase (it_coin);
            
            victim->showWallet ();
        }
        
        lk.unlock ();
        // sleep
        this_thread::sleep_for (chrono::milliseconds (500));
    }
    // stop
    lk.lock();
    cout << "\n[thief] stopped." << endl;
    lk.unlock();
} 


void endFunction (void)
{

    puts ("\nthe work is completed!");
}


int main (void) {


    setlocale (LC_ALL, "");


    if (atexit (endFunction)) {

        puts ("post- function registration error!");
    }

    cout << "Lesson 06. Parallel programming. Multithreading.\n\n";

    // * Exercises #1
    cout << "Exercise #1.\n";

    const size_t m_threads = 10;
    vector <thread> workers_acout;

    for (size_t i = 0; i < m_threads; ++i) {
        workers_acout.emplace_back (thread ([](size_t i) {
            thread::id threadId = this_thread::get_id();    
            unsigned int ThreadIdAsInt = *static_cast <unsigned int*> (static_cast <void*> (&threadId));
            pcout() << "This is worker " << to_string (i) << " in thread " << to_string (ThreadIdAsInt) << '\n';
        }, i));
    }

    for (auto& w : workers_acout)
        w.join();

    cout << "\nExercise #2.\n";


    pBar bar;
    unsigned long number = 0, result;
    do {
        cout << "enter a number" << endl;
        cin  >> number;
        cout << endl;
    } while (number <= 0 && (static_cast<int> (number) != number));

    prime Prime = number;
    Prime.set_pBar (&bar);

    thread th_prime ([&](){result = Prime.calc();});
    th_prime.join();

    cout << "\nthe result is: " << result << endl;



    
    const size_t TTL = 10, delay = 4; // seconds
    owner Owner = TTL;
    thief Thief (&Owner, TTL - delay, delay);


    thread th_owner (&owner::Do, &Owner);
    thread th_thief (&thief::Do, &Thief);

    th_owner.join();
    th_thief.join();


    return EXIT_SUCCESS;
} // main
