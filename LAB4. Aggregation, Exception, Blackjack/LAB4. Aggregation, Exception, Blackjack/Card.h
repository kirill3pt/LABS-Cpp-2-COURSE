#pragma once
#include <string>
enum class Suit
{
    Hearts,   // 0 
    Diamonds, // 1 
    Clubs,    // 2 
    Spades    // 3 
};

class Card {
protected:
    Suit suit_;
    short rank_;
public:
    Card();
    Card(Suit suit, short rank);
    short getRank() const { return rank_; }
    Suit getSuit() const { return suit_; }
    int getValue() const;
    bool isAce() const { return rank_ == 14; }
    std::string toString() const;
};