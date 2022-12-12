#include <iostream>
#include <string>

// template<typename T1, typename T2>
// auto sum(T1 a, T2 b) -> decltype(a+b)
// {
//     return a + b;
// }

// template<typename T>
// class A
// {
// public:
//     void process()
//     {
//         std::cout << a * 100 << std::endl;
//     }
//     T a;
// };

// template<>
// class A<std::string>
// {
// public:
//     void process()
//     {
//         std::cout << a + a << std::endl;
//     }

//     std::string a;
// };

// template<>
// void A<std::string>::process()
// {
//     std::cout << a + a ;
// }

// int main()
// {
//     //auto a = sum(5.5, 3);
//     //std::cout << a;
//     A<double> obj;
//     obj.a = 2.5;
//     obj.process();
//     A<std::string> obj1;
//     obj1.a = "faf";
//     obj1.process();

//     return 0;
// }
template<typename T>
class Pair1
{
public:
    Pair1(T a, T b) : a(a), b(b) {};
    T a, b;
    int first()
    {
        return a;
    }

    int second()
    {
        return b;
    }

};

template<>
class Pair1<double>
{
public:
    Pair1(double a, double b) : a(a), b(b) {};
    const double a, b;
    double first() const
    {
        return a;
    }

    double second() const
    {
        return b;
    }

};

template<typename T1, typename T2>
class Pair
{
public:
    Pair(T1 a, T2 b) : a(a), b(b) {};
    T1 a;
    T2 b;
    auto first() const
    {
        return a;
    }

    auto second() const
    {
        return b;
    }
};

template<typename T3, typename T4>
class PairS
{
public:
    PairS();
    PairS(std::string a, T4 b): a(a), b(b) {};
    std::string a;
    T4 b;

};

template<typename T4>
class StringValuePair : public PairS<std::string, T4>
{
public:
    // StringValuePair(std::string a, T5 b): a(a), b(b) {};
    StringValuePair():PairS<std::string, T4>(a, b){};
    std::string a;
    T4 b;
    auto first()
    {
        return a;
    }
    auto second()
    {
        return b;
    }

};



int main()
{
Pair1<int> p1(6, 9);
std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

const Pair1<double> p2(3.4, 7.8);
std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

Pair<int, double> p3(6, 7.8);
std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

const Pair<double, int> p4(3.4, 5);
std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

StringValuePair<int> svp("Amazing", 7);
std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
return 0;
}

