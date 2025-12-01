#pragma once
#include <vector>
#include <string>
#include "Card.h"

class Hand
{
private:
    std::vector<Card> cards;
public:
    void clear();
    void addCard(const Card& c);
    int getValue() const;       // суммарная ценность
    bool isMore() const;        // перебор > 21
    bool canSplit() const;      // две карты и одинаковый ранг
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream&, const Hand&);
};
