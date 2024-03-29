#include "bg7.h"

using namespace std;



int Card::GetValue() const {

    int value = 0;
    if (m_IsFaceUp) {

        value = m_Rank;

        if (value > 10)
            value = 10;
    }

    return value;
}

void Card::Flip() {
    m_IsFaceUp = !(m_IsFaceUp);
}



Hand::Hand() {
    m_Cards.reserve(7);
}

Hand::~Hand() {
    Clear ();
}

void Hand::Add(Card* pCard) {
    m_Cards.push_back (pCard);
}

void Hand::Clear() {

    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        delete *iter;
        *iter = 0;
    }

    m_Cards.clear();
}

int Hand::GetValue() const {
    if (m_Cards.empty()) return 0;

    if (!m_Cards[0]->GetValue())
        return 0;
    

    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        total += (*iter)->GetValue();


    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        if ((*iter)->GetValue() == Card::ACE)
            containsAce = true;


    if (containsAce && total <= 11)

        total += 10;   

   
    return total;
}



bool GenericPlayer::IsBusted() const { 
    return (GetValue() > 21);
}

void GenericPlayer::Bust() const {
    cout << m_Name << " busts.\n";
}


bool Player::IsHitting() const {
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::Win() const {
    cout << m_Name <<  " wins.\n";
}

void Player::Lose() const {
    cout << m_Name <<  " loses.\n";
}

void Player::Push() const {
    cout << m_Name <<  " pushes.\n";
}



bool House::IsHitting() const {
    return (GetValue() <= 16);
}   

void House::FlipFirstCard() {
    if (!(m_Cards.empty()))
        m_Cards[0]->Flip();
    else 
        cout << "No card to flip!\n";
}



Deck::Deck() { 
    m_Cards.reserve(52);
    Populate();
}

void Deck::Populate() {
    Clear();

    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
        for (int r = Card::ACE; r <= Card::KING; ++r)
            Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
}

void Deck::Shuffle() {
#if __cplusplus > 201100L
    random_device rd;
    mt19937 g(rd());
    shuffle(m_Cards.begin(), m_Cards.end(), g);
#else
    random_shuffle (m_Cards.begin(), m_Cards.end());
#endif
}

void Deck::Deal(Hand& aHand) {
    if (!m_Cards.empty()) {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    } else
        cout << "Out of cards. Unable to deal.";
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer) {
    cout << endl;

    while ( !(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting() ) {
        Deal(aGenericPlayer);
        cout << aGenericPlayer << endl;
        
        if (aGenericPlayer.IsBusted())
            aGenericPlayer.Bust();
    }
} 

// * class Game

Game::Game(const vector<string>& names) {
            
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)      
        m_Players.push_back(Player(*pName));

    srand(time(0));    
    m_Deck.Populate();
    m_Deck.Shuffle();
}

void Game::Play() {         

    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            m_Deck.Deal(*pPlayer);
        m_Deck.Deal(m_House);
    }
    

    m_House.FlipFirstCard();    

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
        cout << *pPlayer << endl;
    cout << m_House << endl;


    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        m_Deck.AdditionalCards(*pPlayer);    


    m_House.FlipFirstCard();    
    cout << endl << m_House; 
  

    m_Deck.AdditionalCards(m_House);

    if (m_House.IsBusted()) {

        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            if ( !(pPlayer->IsBusted()) )
                pPlayer->Win();
    } else {

        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            if ( !(pPlayer->IsBusted()) ) {
                if (pPlayer->GetValue() > m_House.GetValue())
                    pPlayer->Win();
                else if (pPlayer->GetValue() < m_House.GetValue())
                    pPlayer->Lose();
                else
                    pPlayer->Push();
            }
    }


    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
        pPlayer->Clear();
    m_House.Clear();
}

ostream& operator << (ostream& os, const Card& aCard) {
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.m_IsFaceUp)
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    else
        os << "XX";

    return os;
}


ostream& operator << (ostream& os, const GenericPlayer& aGenericPlayer) {
    os << aGenericPlayer.m_Name << ":\t";
    
    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty()) {
        for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard)
            os << *(*pCard) << "\t";
        if (aGenericPlayer.GetValue() != 0)
            cout << "(" << aGenericPlayer.GetValue() << ")";
    } else
        os << "<empty>";
    // return
    return os;
}


void endFunction (void)
{

    puts ("\nthe Game is Over!");
}



int main (void) {


    setlocale (LC_ALL, "");


    if (atexit (endFunction)) {

        puts ("post- function registration error!");
    }

    cout << "\t\tWelcome to Blackjack!\n\n";
    
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }   

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    } 
    

    return EXIT_SUCCESS;
} 
