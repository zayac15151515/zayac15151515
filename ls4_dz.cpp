#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <iterator>

class ArrayInt
{
private:
    int m_length;
    int* m_data;
public:
    ArrayInt() : m_length(0), m_data(nullptr) {}
    ArrayInt(int length) : m_length(length) {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else   
            m_data = nullptr;
    }
    ~ArrayInt() {
        delete[] m_data;
    }
    void erase()
    {
        delete[] m_data;
        m_length = 0;
        m_data = nullptr;
    }
    int& operator[](int index)
    {
        return m_data[index];
    }
    void resize(int newLength)
    {
        if(newLength <= 0)
        {
            erase();
            return;
        }
        int* newData = new int[newLength] {0};
        int CopyElements = 0;
        if (newLength > m_length) CopyElements = m_length;
        else CopyElements = newLength;
        for (size_t i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }
        delete[]m_data;
        m_data = newData;
        m_length = newLength;
    }
    void at(int index, int data)
    {
        if(index >= 0 && index < m_length)
            m_data[index] = data;
    }
    void push_back(int value)
    {
        int* newData = new int[m_length + 1];
        int CopyElements = m_length;
        for (size_t i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }
        newData[m_length] = value;
        delete[] m_data;
        m_data = newData;
        m_length++;
    }
    int pop_up()
    {
        int value = m_data[m_length-1];
        int* newData = new int[m_length - 1];
        int CopyElements = m_length - 1;
        for (size_t i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i];
        }
        newData[m_length] = value;
        delete[] m_data;
        m_data = newData;
        m_length--;

        return value;
    }
    void printArr()
    {
        for (size_t i = 0; i < m_length; i++)
        {
            std::cout << m_data[i] << " ";
        }

        std::cout << std::endl;
    }

    int pop_front()
    {
        int value = m_data[0];
        int* newData = new int[m_length - 1];
        int CopyElements = m_length - 1;
        for (size_t i = 0; i < CopyElements; i++)
        {
            newData[i] = m_data[i+1];
        }
        newData[m_length] = value;
        delete[] m_data;
        m_data = newData;
        m_length--;

        return value;
    }

    void sort()
    {
        for (size_t i = 0; i < m_length - 1; i++)
        {
            for (size_t j = 0; j < m_length - i - 1; j++)
            {
                if(m_data[j] > m_data[j+1])
                {
                    int t = m_data[j+1];
                    m_data[j+1] = m_data[j];
                    m_data[j] = t;
                }
            }
            
        }
        
    }
};

class Card
{
protected:
    bool pos;
    enum num
    {
        ACE     = 1,
        TWO     = 2,
        THREE   = 3,
        FOUR    = 4,
        FIVE    = 5,
        SIX     = 6,
        SEVEN   = 7,
        EIGHT   = 8,
        NINE    = 9,
        JOKER   = 10,
        QUEEN   = 11,
        KING    = 12
    };
    enum suit
    {
        HEART,
        DIAMONDS,
        CLUB,
        SPADE
    };

public:
    //Card(bool pos, enum num, enum suit) : pos(pos), num(num), suit(suit) {}      ~как написать enum в констрактор?
    void Flip(suit, num)
    {
        if(pos == 0)
            pos = 1;
        else
            pos = 0;
    }
    int GetValue(num)
    {
        //return num;                                              ~ по каким параметрам должно выдавать номер карты?
    }
};

class Hand
{
protected:
    std::vector<object> *pCard; //                                ~как передать в вектор путь объекта из Card?
public:
    void setVector(Card object)
    {
        pCard->push_back(object);
    }

};

int main() {

    ArrayInt AI(3);
    AI.at(0, 3);
    AI.at(1, 1);
    AI.at(2, 2);
    AI.push_back(5);
    AI.push_back(4);

    AI.printArr();

    AI.sort();

    AI.printArr();

    std::cout << AI.pop_up() << std::endl;

    AI.printArr();

    std::cout << AI.pop_front() << std::endl;
    
    AI.printArr();

    std::vector<int> V = {1, 3, 4, 2, 6, 7, 1, 2, 5, 6, 9};
    std::vector<int> V1;
    V1.reserve(V.size());
    auto it = V.begin();
    auto it1 = V1.begin();
    int notUniqeNum = 0;

    while (it != V.end())
    {
        std::cout << *it << " ";
        it++;
    }

    std::cout << std::endl;

    
    for (size_t i = 0; i < V.size(); i++)
    {
        for (size_t j = 0; j < V.size(); j++)
        {
            if(V[i] == V[j])
            {
                notUniqeNum++;
            }
        }
        if(notUniqeNum == 1)
            V1.push_back(V[i]);
        notUniqeNum = 0;
    }
    

    while (it1 != V1.end())
    {
        std::cout << *it1 << " ";
        it1++;
    }
    
    std::cout << std::endl;

    std::cout << "Unique Nums: " << V1.size();


    Card C1;
    Hand H1;
    H1.setVector(C1);


    return 0;
}