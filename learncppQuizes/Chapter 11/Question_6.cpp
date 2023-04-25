#include <iostream>
#include <array>
#include <cstddef>
#include <algorithm>
#include <ctime>
#include <random>

enum class Cards
{
  rank2,
  rank3,
  rank4,
  rank5,
  rank6,
  rank7,
  rank8,
  rank9,
  rank10,
  jack,
  queen,
  king,
  ace,
  totalcards,
};

enum class Suits
{
  clubs,
  diamonds,
  hearts,
  spades,
  total_suits,
};

struct Card
{
    Cards rank {};
    Suits suit {};
};

/*
c) Create a printCard() function that takes a const Card reference as a parameter and 
prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).
*/

void printCard(const Card& card)
{
    switch(card.rank)
    {
        case Cards::rank2:  std::cout << '2'; break;
        case Cards::rank3:  std::cout << '3'; break;
        case Cards::rank4:  std::cout << '4'; break;
        case Cards::rank5:  std::cout << '5'; break;
        case Cards::rank6:  std::cout << '6'; break;
        case Cards::rank7:  std::cout << '7'; break;
        case Cards::rank8:  std::cout << '8'; break;
        case Cards::rank9:  std::cout << '9'; break;
        case Cards::rank10: std::cout << 'T'; break;
        case Cards::queen:  std::cout << 'Q'; break;
        case Cards::jack:   std::cout << 'J'; break;
        case Cards::king:   std::cout << 'K'; break;
        case Cards::ace:    std::cout << 'A'; break;

    }
    switch(card.suit)
    {
        case Suits::clubs:    std::cout << 'C'; break;
        case Suits::diamonds: std::cout << 'D'; break;
        case Suits::spades:    std::cout << 'S'; break;
        case Suits::hearts:   std::cout << 'H'; break;
    }
}

/*
d) A deck of cards has 52 cards. Create an array (using std::array) to represent the deck of cards, and 
initialize it with one of each card. Do this in a function named createDeck and 
call createDeck from main. createDeck should return the deck to main.
*/


using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

Deck createDeck()
{
    Deck deckofCards {};
    Index index {0};
    
    for (int i {0}; i < static_cast<int>(Suits::total_suits); ++i)
    {
        for (int j {0}; j < static_cast<int>(Cards::totalcards); ++j)
        {
            deckofCards[index].suit = static_cast<Suits>(i);
            deckofCards[index].rank = static_cast<Cards>(j);
            ++index;
        }
    }
    return deckofCards;
}  

void printDeck(const Deck& deck)
{
    for (const auto& i : deck)
    {
     printCard(i);
     std::cout << ' ';
    }
}

void shuffleDeck(Deck& deck)
{
    static std::mt19937 mt {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
}

//this doesnt work.
int getCardValue(const Card& card)
{
    switch(card.rank)
    {
        case Cards::rank2: return 2;
        case Cards::rank3: return 3;
        case Cards::rank4: return 4;
        case Cards::rank5: return 5;
        case Cards::rank6: return 6;
        case Cards::rank7: return 7;
        case Cards::rank8: return 8;
        case Cards::rank9: return 9;
        case Cards::rank10: return 10;
        case Cards::queen: return 10;
        case Cards::jack: return 10;
        case Cards::king: return 10;
        case Cards::ace: return 11;
        default: std::cout << '?'; return 0;
    }
}

int main()
{
    auto deck { createDeck() };
    shuffleDeck(deck);
    printDeck(deck);
    std::cout << '\n';
    //getCardValue(2);
    return 0;
};
