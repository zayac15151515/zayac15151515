#include <locale.h> 
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <numeric>

using namespace std;

template <typename Container, typename Value>
void insert_sorted(Container& cont, const Value& val) {

	auto it = upper_bound(cont.begin(), cont.end(), val);
	cont.insert(it, val);
}

class wave
{
private:
    float m_amplitude; // Amplitude (A) — we can use it as a volume
    float m_frequency; // Frequency (f) — how many cycles per second it does
    float m_phase;     // Phase (phi)   — starting point of sine wave

public:

    wave(const float _amplitude = 10.0f, const float _frequency = 1.0f, const float _phase = 0.0f)
        : m_amplitude(_amplitude), m_frequency(_frequency), m_phase (_phase) {};

    ~wave() = default;

    void getWave (vector<float_t>& _signal) {
        const size_t count = _signal.size();
        generate(_signal.begin(), _signal.end(),
                [=, m_time = 0]() mutable
                {return m_amplitude * sin(m_time++ * 2 * M_PI / count + m_phase);}
                );
    };
};



void endFunction (void)
{
    
    puts ("\nthe work is completed!");
} 


int main (void) {


    setlocale (LC_ALL, "");


    if (atexit (endFunction)) {

        puts ("post- function registration error!");
    }

    cout << "Lesson 03. STL Algorithms.\n\n";

    cout << "Exercise #1.\n";

    const size_t MAX_SIZE1 = 10;
    vector <int> vec(MAX_SIZE1);

    uniform_int_distribution <int> RNG_INT(0, 20);

    mt19937 gen {random_device()()};

    generate (vec.begin(), vec.end(), [&RNG_INT, &gen]() {return RNG_INT(gen);});

    sort(vec.begin(), vec.end());

    cout << "source vector   : ";
    copy (vec.begin(), vec.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    int rValue = RNG_INT(gen);
    cout << "inserting a random value: " << rValue << endl;

    insert_sorted(vec, rValue);
    cout << "resulting vector: ";
    copy (vec.begin(), vec.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    


    const size_t MAX_SIZE2 = 100;

    wave Wave{};

    vector <float_t> analog(MAX_SIZE2);

    Wave.getWave (analog);

    cout << "analog signal  >> ";
    copy (analog.begin(), analog.end(), ostream_iterator<float_t> (cout, " "));
    cout << endl;

    vector<int64_t> digital(MAX_SIZE2);

    for_each(digital.begin(), digital.end(), 
            [analog, n = 0](int64_t &value) mutable
            {value = static_cast<int64_t>(round(analog[n++]));}
            );

    cout << "digital signal >> ";
    copy (digital.begin(), digital.end(), ostream_iterator<int64_t> (cout, " "));
    cout << endl;

    float_t mathErr{};
    for_each(digital.begin(), digital.end(), 
            [&mathErr, analog, n = 0](int64_t value) mutable
            {mathErr += pow (analog[n++] - static_cast<float_t>(value), 2);}
            );
    cout << "value of digital signal error: " << mathErr << endl;

    return EXIT_SUCCESS;
} 
