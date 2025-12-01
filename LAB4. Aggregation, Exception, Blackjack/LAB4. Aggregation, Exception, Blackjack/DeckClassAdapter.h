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
        for (int c : cardsLeftEach()) {
            result += "[" + std::to_string(c) + "] ";
        }
        return result;
    }
};