
#include <iostream>
#include <iomanip>
#include <ctime>
#include <memory>

using namespace std;

using uint = unsigned int; 

class Date
{
private:
    uint m_day;
    uint m_month;
    uint m_year;

public:
    enum Month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

    Date (uint _dd = 14, uint _mm = 12, uint _yyyy = 1972);
    Date (const Date&);
    ~Date () = default;

    uint day () const; // Getter signature
    uint day (uint);   // Setter signature (returns the old value)

    uint month () const;
    uint month (uint);

    uint year () const;
    uint year (uint);

    // friends
    friend ostream& operator <<(ostream&, const Date&);
}; // class Date

Date::Date (uint _dd, uint _mm, uint _yyyy) {
    year (_yyyy);
    month (_mm);
    day (_dd);
}

Date::Date(const Date &obj) {
    year (obj.year());
    month (obj.month());
    day (obj.day());
}

ostream& operator <<(ostream& output, const Date& value) {
    output << setfill('0') << setw(2) << value.day() << "-"
            << value.month() << "-" << setw(4) << value.year();
    return output;
}

uint Date::day () const {
    return m_day;
}

uint Date::day(uint _day) {

    auto leapYear = [=]() {

        if(m_year % 4)
            return false;
        if(m_year % 100)
            return true;
        if(m_year % 400)
            return false;
        // return
        return true;
    };

    // max day
    int maxDay ((7 < m_month) ? 31 - m_month % 2 : 30 + m_month % 2);
    if (m_month == 2) {
        if(leapYear()) {
            maxDay = 29;
        } else {
            maxDay = 28;
        }
    }
    uint prev_day = m_day;

    if (!_day)
        m_day = 1;
    else if (_day % maxDay)
        m_day = _day % maxDay;
    else
        m_day = maxDay;

    return prev_day;
}

uint Date::month () const {
    return m_month;
}

uint Date::month (uint _month) {
    uint prev_month = m_month;


    if (!_month)
        m_month = jan;
    else if (_month % dec)
        m_month = _month % dec;
    else
        m_month = dec;

    return prev_month;
}

uint Date::year () const {
    return m_year;
}

uint Date::year (uint _year) {
    uint prev_year = m_year;
    m_year = _year;

    return prev_year;
}


Date latestDate (const shared_ptr<Date> value1, const shared_ptr<Date> value2) {

    if (value1->year() > value2->year())
        return *value1.get();
    else if (value1->year() < value2->year())
        return *value2.get();
    // value1->year() == value2->year()
    if (value1->month() > value2->month())
        return *value1.get();
    else if (value1->month() < value2->month())
        return *value2.get();

    if (value1->day() > value2->day())
        return *value1.get();
    else if (value1->day() < value2->day())
        return *value2.get();



   
    return *value1.get();
} 

void swapDates (shared_ptr<Date>& value1, shared_ptr<Date>& value2) {
    shared_ptr<Date> temp = value1;
    value1 = value2;
    value2 = temp;
} 


void endFunction (void)
{
   
    puts ("\nthe work is completed!");
} 

// main
int main (void) {

    
    setlocale (LC_ALL, "");

     
    if (atexit (endFunction)) {
        
        puts ("post- function registration error!");
    }

    cout << "Lesson 07. Modularity support. Writing a Blackjack Game.\n\n";

   
    cout << "Exercise #1.\n";

    time_t t = time(0); 
    tm* now = localtime(&t);

    auto today = make_unique<Date>(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    cout << "«*today» is " << *today << "." << endl;
    cout << "day -> " << today->day() << ", month -> " << today->month()
            << ", year -> " << today->year() << "." << endl;

    auto date = move(today);
    cout << "ownership of the smart pointer has been transferred from «*today» to «*date»." << endl;
    cout << "now «*date» is " << *date << "." << endl;

    if (today == nullptr) {
        cout << "now «today» is nullptr!" << endl;
    }

   
    cout << "\nExercise #2.\n";
    auto date1 = make_shared<Date> ();
    auto date2 = make_shared<Date> (now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    cout << "«*date1» is " << *date1 << "." << endl;
    cout << "«*date2» is " << *date2 << "." << endl;
    cout << "latest date is " << latestDate (date1, date2) << "." << endl;
    cout << "date1 use count: " << date1.use_count() << "." << endl;
    cout << "date2 use count: " << date2.use_count() << "." << endl;
    swapDates (date1, date2);
    cout << "data exchange between «*data1» and «*data2»..." << endl;
    cout << "now «*date1» is " << *date1 << "." << endl;
    cout << "now «*date2» is " << *date2 << "." << endl;
    cout << "date1 use count: " << date1.use_count() << "." << endl;
    cout << "date2 use count: " << date2.use_count() << "." << endl;


   
    return EXIT_SUCCESS;
}
