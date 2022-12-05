#include <iostream>
#include <cmath>
 
class Figure
{
public:
    virtual double area() = 0;
};
class Parallelogram : public Figure
{
protected:
    double width;
    double height;
    double a;
public:
    Parallelogram();
    Parallelogram(double a, double h) : a(a), height(h)
    {
    }
    double area() override
    {
        return a * height;
    }
};
class Circle : public Figure
{
private:
    double radius;
public:
    Circle();
    Circle(double r) : radius(r)
    {
    }
    double area() override
    {
        return radius * radius * 3.14;
    }
};

class Rectangle : public Parallelogram
{
protected:
    double width;
    double height;
public:
    Rectangle();
    Rectangle(double w, double h) : width(w), height(h)
    {
    }
    double area() override
    {
        return width * height;
    }
};

class Square : public Parallelogram
{
protected:
    double width;
public:
    Square();
    Square(double w) : width(w)
    {
    }
    double area() override
    {
        return pow(width, 2);
    }
};

class Rhombus : public Parallelogram
{
protected:
    double width;
    double height;
    double a;
public:
    Rhombus();
    Rhombus(double a, double h) : a(a), height(h)
    {
    }
    double area() override
    {
        return a * height;
    }
};


class Car
{   
    protected:
    Car();
    std::string company;
    std::string model;
    
};

class PassengerCar : public Car
{
    protected:
    std::string company;
    std::string model;
    public:
    PassengerCar();
    PassengerCar(std::string c, std::string m) : company(c), model(m)
    {
        std::cout << company << model << std::endl;
    }
};

class Bus : public Car
{
    protected:
    std::string company;
    std::string model;
    public:
    Bus();
    Bus(std::string c, std::string m) : company(c), model(m)
    {
        std::cout << company << model << std::endl;
    }
};

class Minivan : public PassengerCar, public Bus
{
    protected:
    std::string company;
    std::string model;
    public:
    Minivan();
    Minivan(std::string c, std::string m) : company(c), model(m)
    {
        std::cout << company << model << std::endl;
    }
};

class Fraction
{
   int numerator;
   int denominator;
};

class Card
{
    int pos;
    int num;
    std::string suit;
};




 
int main()
{
    Parallelogram para(5, 60);
    Circle circle(45);
    Square square(10);
    Rhombus rhombus(5, 60);
     
    std::cout << "Rectangle area: " << para.area() << std::endl;
    std::cout << "Circle area: " << circle.area() << std::endl;
    std::cout << "Square area: " << square.area() << std::endl;
    std::cout << "Rhombus area: " << rhombus.area() << std::endl;

    PassengerCar pcar("Mercedes", "CLS");
    Bus bus("BMW", "M2");
    Minivan mini("Fleetwood", "Bounder");
 
    return 0;
}