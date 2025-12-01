#pragma once
#include <string>
#include <iostream>
#include "Deck.h"
#include "IFormattable.h"
class DeckClassAdapter : public Deck, public IFormattable {
public:
    DeckClassAdapter(const Deck& d) : Deck(d) {}
    std::string format() const override {
        std::string result = "Колоды №1: ";
        const std::vector<int>& counts = cardsLeftEach();
        for (size_t i = 0; i < counts.size(); ++i) {
            result += "(" + std::to_string(counts[i]) + ") ";
        }
        return result;
    }
};