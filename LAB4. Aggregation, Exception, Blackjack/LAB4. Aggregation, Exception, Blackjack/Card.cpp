#include <iostream>
#include "Card.h"
#include <string>
Card::Card() : suit_(Suit::Hearts), rank_(2) {}
Card::Card(Suit suit, short rank) : suit_(suit), rank_(rank) {}

int Card::getValue() const
{
    if (rank_ >= 2 && rank_ <= 10) {
        return rank_;
    }
    if (rank_ >= 11 && rank_ <= 13) {
        return 10; // J, Q, K
    }
    if (rank_ == 14) {
        return 11; // туз по умолчанию 11
    }
    return 0;
}
std::string Card::toString() const
{
    std::string rankStr;
    switch (rank_)
    {
        case 11: rankStr = "J"; break;
        case 12: rankStr = "Q"; break;
        case 13: rankStr = "K"; break;
        case 14: rankStr = "A"; break;
        default: rankStr = std::to_string(rank_); break;
    }
    std::string suitStr;
    switch (suit_) {
        case Suit::Hearts:   suitStr = static_cast<char>(3); break;  // ♥
        case Suit::Diamonds: suitStr = static_cast < char>(4); break;  // ♦
        case Suit::Clubs:    suitStr = static_cast < char>(5); break;  // ♣
        case Suit::Spades:   suitStr = static_cast < char>(6); break;  // ♠
    }
    return rankStr + suitStr;
}