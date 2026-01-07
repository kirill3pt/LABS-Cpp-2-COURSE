#pragma once
#include "Book.h"

class BookSorter
{
public:
    bool operator()(const Book* a, const Book* b) const
    {
        if (a->getAuthor() == b->getAuthor())
        {
            return a->getName() < b->getName();
        }
        return a->getAuthor() < b->getAuthor();
    }
};
