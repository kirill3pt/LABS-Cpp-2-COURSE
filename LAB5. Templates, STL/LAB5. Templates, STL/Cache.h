#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>

template<typename T>
class Cache {
private:
    std::vector<T> data;
public:
    void put(const T& elem) {
        data.push_back(elem);
    }
    void operator+=(const T& elem) {
        put(elem);
    }
    bool contains(const T& elem) const {
        return std::find(data.begin(), data.end(), elem) != data.end();
    }
};
template<>
class Cache<std::string> {
private:
    std::vector<std::string> data;
    static const size_t MAX_SIZE = 100;
public:
    void put(const std::string& elem) {
        if (data.size() >= MAX_SIZE) {
            throw std::runtime_error("Лимит");
        }
        data.push_back(elem);
    }
    void operator+=(const std::string& elem) {
        put(elem);
    }
    bool contains(const std::string& elem) const {
        if (elem.empty()) return false;
        char firstChar = elem[0];
        for (const auto& s : data) {
            if (!s.empty() && s[0] == firstChar) {
                return true;
            }
        }
        return false;
    }
};