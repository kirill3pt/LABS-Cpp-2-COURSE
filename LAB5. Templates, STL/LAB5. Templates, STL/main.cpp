#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "DataManager.h"
#include "Text.h"
#include "Book.h"
#include "Book4th.h"
#include "BookSorter.h"
#include "BookFinder.h"
#include "Cache.h"

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    std::cout << "Выберите задание:\n1 - задание №1\n2 - задание №2\n3 - задание №3\n4 - задание №4\n5 - задание №5: ";
    std::cin >> choice;
    switch (choice) {
    case 1: {
        DataManager<int> manager;
        manager.push(-9);

        int a[60] = { 0 };
        manager.push(a, 60);

        int x = manager.peek();

        for (int i = 1; i < 15; ++i) {
            manager.push(i);
        }

        x = manager.pop();

        DataManager<char> char_manager;
        char_manager.push('h');
        char_manager.push('e');
        char_manager.push('l');
        char_manager.push('l');
        char_manager.push('o');

        char ch = char_manager.popUpper();
        std::cout << ch << std::endl;
        break;
    }
    case 2: {
        Text::analyzeFile("text.txt");
        break;
    }
    case 3: {
        setlocale(LC_ALL, "RUSSIAN");

        std::vector<Book*> books;

        books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
        books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
        books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
        books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
        books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
        books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
        books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
        books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
        books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));

        std::cout << "\nКниги в алфавитном порядке:\n\n";

        BookSorter book_sorter;
        std::sort(books.begin(), books.end(), book_sorter);

        std::vector<Book*>::iterator i;
        for (i = books.begin(); i != books.end(); ++i)
        {
            std::cout << (*i)->getAuthor() << " \""
                << (*i)->getName() << "\"" << std::endl;
        }
        BookFinder book_finder(1990, 2010);
        std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
        std::cout << "\nКниги в диапазоне года издания 1990 - 2010:\n\n";

        while (finder != books.end())
        {
            std::cout << (*finder)->getAuthor() << " \"" << (*finder)->getName() << "\"" << std::endl;
            finder = std::find_if(++finder, books.end(), book_finder);
        }
        for (i = books.begin(); i != books.end(); ++i)
        {
            delete (*i);
        }
        break;
    }
    case 4: {
        std::vector<Book*> books;

        books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
        books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
        books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
        books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
        books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
        books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
        books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
        books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
        books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));
        std::vector<int> years;
        std::transform(books.begin(), books.end(), std::back_inserter(years), Year());
        int count = std::count_if(years.begin(), years.end(), Greater(2009));
        std::cout << "Книг новее 2009 года: " << count << std::endl;
        break;
    }
    case 5: {
        Cache<int> cache;
        cache.put(1);
        cache.put(2);
        cache.put(3);
        cache += 5;

        Cache<std::string> voc;
        voc.put("OK");
        std::cout << voc.contains("Only") << std::endl;
        std::cout << cache.contains(5) << std::endl;
    }
    }
    return 0;
}