#include "Player.h"
#include <stdexcept>

void Player::addCard(const Card& c) {
    hand_.push_back(c);
}
int Player::getPoints() const {
    int sum = 0;
    int aces = 0;
    for (size_t i = 0; i < hand_.size(); ++i) {
        sum += hand_[i].getValue();
        if (hand_[i].isAce()) {
            aces++;
        }
    }
    while (sum > 21 && aces > 0) {
        sum -= 10;  // превращаем один туз из 11 в 1
        aces--;
    }
    if (sum > 21) {
        throw std::overflow_error("Перебор!");
    }
    return sum;
}
bool Player::isBlackjack() const {
    const auto& hand = getHand();
    if (hand.size() == 2 && getPoints() == 21) {
        return true;
    }
    return false;
}