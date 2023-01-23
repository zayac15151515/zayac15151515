
#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Card
{
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};           
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
    
    Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {};

    int GetValue() const;

    void Flip();

    friend ostream& operator<<(ostream& os, const Card& aCard);

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

class Hand
{
public:
    Hand();
    virtual ~Hand();


    void Add(Card* pCard);


    void Clear();


    int GetValue() const;

protected:
    vector<Card*> m_Cards;
};

class GenericPlayer : public Hand
{
public:
    GenericPlayer(const string& name = "") : m_Name(name) {};
    virtual ~GenericPlayer() {};


    virtual bool IsHitting() const = 0;


    bool IsBusted() const;

    void Bust() const;


    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

protected:
    string m_Name;
};


class Player : public GenericPlayer
{
public:
    Player(const string& name = "") : GenericPlayer(name) {};
    virtual ~Player() {};

     
    virtual bool IsHitting() const;


    void Win() const;


    void Lose() const;

    void Push() const;
};


class House : public GenericPlayer
{
public:
    House(const string& name = "House") : GenericPlayer(name) {};
    virtual ~House() {};


    virtual bool IsHitting() const;

    void FlipFirstCard();
};

class Deck : public Hand
{
public:
    Deck();
    virtual ~Deck();


    void Populate();


    void Shuffle();

    void Deal(Hand& aHand);

    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

class Game
{
public:
    Game(const vector<string>& names);
    ~Game();

    void Play();
private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;  
};



ostream& operator << (ostream& os, const Card& aCard);
ostream& operator << (ostream& os, const GenericPlayer& aGenericPlayer);

#endif 
