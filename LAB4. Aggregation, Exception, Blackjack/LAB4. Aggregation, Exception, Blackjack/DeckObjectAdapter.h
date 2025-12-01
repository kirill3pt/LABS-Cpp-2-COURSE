#pragma once
#include <string>
#include <iostream>
#include "Deck.h"
#include "IFormattable.h"
class DeckObjectAdapter : public IFormattable {
private:
    const Deck& deck;
public:
    DeckObjectAdapter(const Deck& d) : deck(d) {}
    std::string format() const override {
        std::string result = "Колоды №2: ";
        const std::vector<int>& counts = deck.cardsLeftEach();
        for (size_t i = 0; i < counts.size(); ++i) {
            result += "<" + std::to_string(counts[i]) + "> ";
        }
        return result;
    }
};