#pragma once
#include "Book.h"

class BookFinder
{
private:
    int from;
    int to;

public:
    BookFinder(int from, int to) : from(from), to(to) {}

    bool operator()(const Book* b) const
    {
        return b->getYear() >= from && b->getYear() <= to;
    }
};