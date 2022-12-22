
#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <sstream>
#include <limits>

using namespace std;

double askNumber(string prompt) {
    double value;
    cout << prompt << ": ";
    cin >> value;
    while (cin.fail() || cin.get() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.sync();
        cout << "error!\n\n" << prompt << ": ";
        cin >> value;
    }
    return value;
}

class DivisionByZero {};

template<typename T1, typename T2>
auto div (T1 x, T2 y) -> decltype (x/y) {
    if (!y)
        throw DivisionByZero();
    return x / y;
}


class Ex {
private:
    double x;
public:
    Ex(const double &_x) : x(_x) {};
    ~Ex()= default;
    double get() const {return x;};
};

class Bar {
private:
    double y;
public:
    Bar() {y = 0;};
    ~Bar() = default;
    void set(const double &a) {
        if (y + a <= 100)
            y = a;
        else
            throw Ex (y * a);
    };
    double get() const {return y;};
};

#define MAX_SIZE 10
using uint = unsigned int; 


class OffTheField
{
private:
    const uint xR;
    const uint yR;
    const string command;

public:
    OffTheField (uint _x, uint _y, string _command) :
        xR (_x), yR (_y), command (_command) {};
    ~OffTheField() = default;
    string what();
}; 

string OffTheField::what() {
    stringstream out;
    out << "An «OffTheField» exception was handled! " <<
            "Coordinates [" << xR << "][" << yR << "]. " <<
            "The last command: «" << command << "»." << endl;
    return out.str();
}


class IllegalCommand
{
private:
    const char command;

public:
    IllegalCommand (char _command) :
        command (_command) {};
    ~IllegalCommand() = default;
    string what();
}; 

string IllegalCommand::what() {
    stringstream out;
    out << "An «IllegalCommand» exception was handled! " <<
            "Unknown command: «" << command << "»." << endl;
    return out.str();
}


class Robot
{
private:
    uint xR, yR;
    uint RandInt();

    void Info();
    void Display ();
    void Up();
    void Down();
    void Left();
    void Right();

public:
    Robot (uint _x = 0, uint _y = 0);
    ~Robot () = default;

    void Run();
};

uint Robot::RandInt() {
    return rand() % 10;
}

Robot::Robot(uint _x, uint _y) {
    srand((uint) time(0));
    xR = !_x ? RandInt() : _x % MAX_SIZE;
    yR = !_y ? RandInt() : _y % MAX_SIZE;
}

void Robot::Display() {
    // шапка
    for (int i = 0; i < MAX_SIZE; ++ i)
        cout << (!i ? "\n   | " : "") << i <<  " | ";
    for (int i = 0; i < MAX_SIZE; ++ i)
        cout << (!i ? "\n----" : "") << "----";
    // поле
    for (int y = 0; y < MAX_SIZE; ++y) {
        cout << "\n " << y <<  " | ";
        for (int x = 0; x < MAX_SIZE; ++x) {
            cout << ((y == yR && x == xR) ? "R" : " ") << " | ";
        }
    }
    // подвал
    for (int i = 0; i < MAX_SIZE; ++ i)
        cout << (!i ? "\n----" : "") << "----";
}

void Robot::Info() {
    cout << endl;
    cout << "W -> one cell up.\n";
    cout << "S -> one cell down.\n";
    cout << "A -> one cell left.\n";
    cout << "D -> one cell right.\n";
    cout << "0 -> exit the program.\n";
}

void Robot::Up() {
    if (!yR)
        throw OffTheField(xR, yR, __FUNCTION__);
    else
        --yR;
}

void Robot::Down() {
    if (yR == MAX_SIZE - 1)
        throw OffTheField(xR, yR, __FUNCTION__);
    else
        ++yR;
}

void Robot::Left() {
    if (!xR)
        throw OffTheField(xR, yR, __FUNCTION__);
    else
        --xR;
}

void Robot::Right()  {
    if (xR == MAX_SIZE - 1)
        throw OffTheField(xR, yR, __FUNCTION__);
    else
        ++xR;
}

void Robot::Run() {
    cout << "Welcome to the Robot control program.\n";
    for (;;) {
        Display();
        Info();
        cout << "command?: ";
        char input = getch();
        switch (input) {
        case ('W','w'):
            Up();
            break;
        case ('S','s'):
            Down();
            break;
        case ('A','a'):
            Left();
            break;
        case ('D','d'):
            Right();
            break;
        case 0:
            cout << "exit..." << endl;
            return;
        default:
            throw IllegalCommand(input);
        }
    }
}


void endFunction (void)
{

    puts ("\nthe work is completed!");
} // endFunction

// main
int main (void) {


    if (atexit (endFunction)) {
      
        puts ("post- function registration error!");
    }

    cout << "Lesson 08. The mechanism of exceptional situations.\n\n";

    // * Exercise #1
    cout << "Exercise #1.\n";
    double x = askNumber("input X");
    double y = askNumber("input Y");
    try {
        cout << x << " / " << y << " = " << div (x , y) << endl;
    }
    catch (DivisionByZero) {
        cerr << endl << "division by zero!" << endl;

    }

 
    Bar b;
    for (;;) {
        double N = askNumber("input N");
        if (!N)
            break;
        try {
            b.set(N);
            cout << "B.y = " << b.get() << endl;
        }
        catch(Ex &err) {
            cerr << "exception: a * y = " << err.get() << endl;

            break;
        };
    };

    Robot robot;
    try {
        robot.Run();
    }
    catch (OffTheField &ex) {
        cerr << endl << ex.what() << endl;

    }
    catch (IllegalCommand &ex) {
        cerr << endl << ex.what() << endl;

    }


    return EXIT_SUCCESS;
}
