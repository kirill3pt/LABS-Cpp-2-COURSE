#pragma once
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
    Card(Suit suit, size_t numberCard);
};