#include "Deck.h"
#include <algorithm>
#include <stdexcept>
#include <string>

Deck::Deck(int numDecks, int cardsPerDeck) : currentDeckIndex(0) {
    decks.resize(numDecks);

    for (int d = 0; d < numDecks; ++d) {
        for (int s = 0; s < 4; ++s) {
            Suit suit = static_cast<Suit>(s);
            int startRank = (cardsPerDeck == 36) ? 6 : 2;
            int endRank = 14;

            for (int r = startRank; r <= endRank; ++r) {
                decks[d].push_back(Card(suit, r));
            }
        }
    }
}
void Deck::shuffle() {
    std::srand(std::time(nullptr));
    for (size_t i = 0; i < decks.size(); ++i) {
        for (int j = decks[i].size() - 1; j > 0; --j) {
            int k = rand() % (j + 1);
            std::swap(decks[i][j], decks[i][k]);
        }
    }
}
Card Deck::dealCard() {
    size_t attempts = 0;
    while (attempts < decks.size()) {
        if (!decks[currentDeckIndex].empty()) {
            Card c = decks[currentDeckIndex].back();
            decks[currentDeckIndex].pop_back();
            currentDeckIndex = (currentDeckIndex + 1) % decks.size();
            return c;
        }
        currentDeckIndex = (currentDeckIndex + 1) % decks.size();
        ++attempts;
    }
    throw std::out_of_range("Все колоды пусты");
}
std::vector<int> Deck::cardsLeftEach() const {
    std::vector<int> counts;
    for (size_t i = 0; i < decks.size(); ++i) {
        counts.push_back(static_cast<int>(decks[i].size()));
    }
    return counts;
}
size_t Deck::totalCardsLeft() const {
    size_t total = 0;
    for (size_t i = 0; i < decks.size(); ++i) {
        total += decks[i].size();
    }
    return total;
}

