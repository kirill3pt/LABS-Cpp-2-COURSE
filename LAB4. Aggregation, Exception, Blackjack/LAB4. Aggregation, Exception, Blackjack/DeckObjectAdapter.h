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
        for (int c : deck.cardsLeftEach()) {
            result += "[" + std::to_string(c) + "] ";
        }
        return result;
    }
};