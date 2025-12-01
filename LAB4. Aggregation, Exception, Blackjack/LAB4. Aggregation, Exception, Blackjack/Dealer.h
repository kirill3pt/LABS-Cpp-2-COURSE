#pragma once
#include "Player.h"
#include "Deck.h"
#include <iostream>

class Dealer : public Player {
public:
    Dealer() = default;
    void play(Deck& deck); //агрегация
    void showInitialHand(std::ostream& os) const;
    void showHand(std::ostream& os) const;
    bool isBlackjack() const;
};