#pragma once
#include <string>

class Book
{
private:
    std::string name;
    std::string author;
    int year;

public:
    Book(const std::string& name, const std::string& author, int year)
        : name(name), author(author), year(year) {
    }

    const std::string& getName() const { return name; }
    const std::string& getAuthor() const { return author; }
    int getYear() const { return year; }
};