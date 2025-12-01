#include "Dealer.h"
#include <stdexcept>

void Dealer::play(Deck& deck) {
    while (true) {
        int points;
        try {
            points = getPoints();
        }
        catch (const std::overflow_error&) {
            throw;
        }
        if (points >= 17) {
            break;
        }
        addCard(deck.dealCard());
    }
}
void Dealer::showInitialHand(std::ostream& os) const {
    const auto& cards = getHand();
    if (!cards.empty()) {
        os << cards[0].toString();
    }
}
void Dealer::showHand(std::ostream& os) const {
    const auto& cards = getHand();
    for (size_t i = 0; i < cards.size(); ++i) {
        os << cards[i].toString() << " ";
    }
}
bool Dealer::isBlackjack() const {
    const auto& hand = getHand();
    if (hand.size() == 2 && getPoints() == 21) {
        return true;
    }
    return false;
}