#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>

void Text::analyzeFile(const std::string& filename)
{
    std::ifstream f(filename);
    if (!f)
    {
        std::cout << "Не удалось открыть файл!\n";
        return;
    }

    std::map<std::string, int> freq;

    const size_t MAXLEN = 1000;
    char text[MAXLEN];

    while (f.getline(text, MAXLEN))
    {
        char* substr = std::strtok(text, ".,:!;?- ");

        while (substr != nullptr)
        {
            std::string word = substr;

            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });

            if (word.length() > 3)
            {
                freq[word]++;
            }

            substr = std::strtok(nullptr, ".,:!;?- ");
        }
    }

    f.close();

    std::vector<std::pair<std::string, int>> result;

    for (const auto& p : freq)
    {
        if (p.second >= 7)
        {
            result.push_back(p);
        }
    }

    std::sort(result.begin(), result.end(), [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });

    for (const auto& p : result)
    {
        std::cout << p.first << " " << p.second << "\n";
    }
}