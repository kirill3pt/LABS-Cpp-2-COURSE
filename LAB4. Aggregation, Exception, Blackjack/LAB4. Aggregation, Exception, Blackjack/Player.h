#pragma once
#include <vector>
#include "card.h"

class Player {
private:
    std::vector<Card> hand_;   // агрегация — игрок владеет своими картами
public:
    Player() = default;
    void addCard(const Card& c);
    int getPoints() const;
    size_t cardCount() const { return hand_.size(); }
    const std::vector<Card>& getHand() const { return hand_; }
    void clear() { hand_.clear(); }
    bool isBlackjack() const;
};