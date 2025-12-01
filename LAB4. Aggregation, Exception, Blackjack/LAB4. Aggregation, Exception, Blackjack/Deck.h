#pragma once
#include <vector>
#include "Card.h"
#include <random>

class Deck {
private:
   std::vector<std::vector<Card>> decks;
   size_t currentDeckIndex = 0;  // индекс колоды, из которой будет браться карта
public:
    Deck(int numDecks = 4, int cardsPerDeck = 52);
    void shuffle();
    Card dealCard();
    std::vector<int> cardsLeftEach() const;
    size_t totalCardsLeft() const;
};