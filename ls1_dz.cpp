#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>

class Power
{
    private:
    float num_1;
    float num_2;
    float result;
    public:
    void setNums(float _num1, float _num2)
    {
        num_1 = _num1;
        num_2 = _num2;
    }
    float culculate()
    {
        return result = pow(num_1, num_2);
    }
};

class RGBA
{
    private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 0;

    public:
    RGBA(std::uint8_t _m_red, std::uint8_t _m_green, std::uint8_t _m_blue, std::uint8_t _m_alpha)
    {
        m_red = _m_red;
        m_green = _m_green;
        m_blue = _m_blue;
        m_alpha = _m_alpha;
    }

    void PrintRGBA()
    {
        std::cout <<  m_red <<  " " <<  m_green << " " << m_blue << " " << m_alpha << std::endl;
    }
};

class Stack
{
    public:
    void reset()
    {
        for (size_t i = 1; i <= size; i++)
        {
            arr[i] = 0;
        }
        size = 0;
    }
    void push(int num)
    {
        for (size_t i = 1; i <= size; i++)
        {
            if(arr[i] != 0)
                arr[i] = num;
            size = i;
            
        }
        
    }
    void print()
    {
        for (size_t i = 1; i <= size; i++)
        {
            std::cout << "\n";
            std::cout << arr[i] << " | ";
        }
        
    }
    void pop();

    private:
    int size = 10;
    int arr[10];
    
};


int main ()
{
    Power FIRST;
    FIRST.setNums(5, 2);
    std::cout << FIRST.culculate() << std::endl;

    RGBA Color(50, 60, 15, 255);
    Color.PrintRGBA();

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    return 0;
}
