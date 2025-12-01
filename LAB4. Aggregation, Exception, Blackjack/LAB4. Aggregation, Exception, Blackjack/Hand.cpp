#include "hand.h"
#include <iostream>

void Hand::clear() {
    cards.clear();
}
void Hand::addCard(const Card& c) {
    cards.push_back(c);
}
int Hand::getValue() const {
    int sum = 0;
    int aces = 0;
    for (size_t i = 0; i < cards.size(); ++i) {
        sum += cards[i].getValue();
        if (cards[i].isAce()) {
            aces++;
        }
    }
    while (sum > 21 && aces > 0) {
        sum -= 10; // превращаем один туз 11 → 1
        aces--;
    }
    return sum;
}
bool Hand::isMore() const {
    return getValue() > 21;
}
bool Hand::canSplit() const {
    return cards.size() == 2 && cards[0].getRank() == cards[1].getRank();
}
std::string Hand::toString() const {
    std::string res;
    for (size_t i = 0; i < cards.size(); ++i) {
        res += cards[i].toString() + " ";
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
    for (size_t i = 0; i < hand.cards.size(); ++i) {
        os << hand.cards[i].toString() << " ";
    }
    return os;
}