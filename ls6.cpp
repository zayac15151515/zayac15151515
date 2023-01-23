#include <locale.h> 
#include <iostream>
#include <limits>
#include <string>
#include <iosfwd>

using namespace std;



class mCheck
{
public:
    string prompt;
    mCheck& operator >> (string& str) 
    {
        getline(cin, str);
        prompt = "";
        return *this;
    };
    mCheck& operator >> (unsigned char& ch) 
    {
        bool     is_error;
        unsigned n;
        do {
            cin  >> n;
            is_error = cin.fail() || cin.get() != '\n';
            if (is_error) {
                cout << "Error!\n\n" << prompt;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.sync();
            }
            else if(n > 255) {
                is_error  = true;
                cout << "Error bound!\n\n" << prompt;
            }
        } while (is_error);

        ch = n;
        prompt = "";
        return *this;
    };
    mCheck& operator >>(const char* _prompt) //-----------------promt
    {
        cout << _prompt;
        prompt = _prompt;
        return *this;
    };
    template<class T>
    mCheck& operator >> (T& value) //---------------------------template:
    {
        cin >> value;
        while (cin.fail() || cin.get() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.sync();
            cout << "Error!\n\n" << prompt;
            cin >> value;
        }
        prompt = "";
        return *this;
    };
} cin_check;



template <class _Elem, class _Traits>
basic_ostream<_Elem, _Traits>& endll(
    basic_ostream<_Elem, _Traits>& _Ostr) { 
    _Ostr.put(_Ostr.widen('\n'));
    _Ostr.put(_Ostr.widen('\n'));
    _Ostr.flush();
    return _Ostr;
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

    cout << "Lesson 06. I/O Streams.\n\n";

    cout << "Exercise #1.\n";

    int number;
    cout << "int------------------------:\n";
    cin_check >> "n = " >> number;
    cout << "validator: " << number << endll;


    return EXIT_SUCCESS;
} 
