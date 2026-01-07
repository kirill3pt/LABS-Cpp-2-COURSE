#pragma once
#include "Book.h"

struct Year {
    int operator()(Book* b) const {
        return b->getYear();
    }
};

struct Greater {
    int value;
    Greater(int v) : value(v) {}
    bool operator()(int x) const {
        return x > value;
    }
};