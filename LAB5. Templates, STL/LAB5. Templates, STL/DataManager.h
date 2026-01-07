#pragma once
#include <iostream>
#include <fstream>
#include <cctype>
#include <iterator>

template<typename T>
class DataManager {
private:
    static const size_t MAX = 64;
    T data[MAX];
    size_t size_ = 0;

    void dumpToFile() {
        std::ofstream f("dump.dat", std::ios::app | std::ios::binary);
        for (size_t i = 0; i < size_; ++i) {
            f.write((char*)&data[i], sizeof(T));
        }
        f.close();
        size_ = 0;
    }

    void loadFromFile() {
        std::ifstream f("dump.dat", std::ios::binary);
        if (!f) return;

        f.seekg(0, std::ios::end);
        size_t bytes = f.tellg();
        if (bytes == 0) return;

        size_t count = bytes / sizeof(T);
        if (count > MAX) count = MAX;

        f.seekg(bytes - count * sizeof(T), std::ios::beg);
        for (size_t i = 0; i < count; ++i) {
            f.read((char*)&data[i], sizeof(T));
        }
        f.close();

        std::ofstream clear("dump.dat", std::ios::trunc);
        clear.close();

        size_ = count;
    }

public:
    void push(T elem) {
        if (size_ >= MAX) {
            dumpToFile();
        }
        for (size_t i = size_; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = elem;
        ++size_;
    }

    void push(T elems[], size_t n) {
        for (size_t i = 0; i < n; ++i) {
            push(elems[i]);
        }
    }

    T peek() const {
        if (size_ == 0 || size_ % 2 == 0) {
            return T(0);
        }
        return data[size_ / 2];
    }

    T pop() {
        if (size_ == 0) {
            loadFromFile();
            if (size_ == 0) {
                return T(0);
            }
        }

        size_t index;
        if (size_ % 2 == 0) {
            index = size_ / 2 - 1;
        }
        else {
            index = size_ / 2;
        }
        T value = data[index];
        for (size_t i = index; i + 1 < size_; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
        if (size_ == 0) {
            loadFromFile();
        }

        return value;
    }

    size_t size() const { return size_; }

    void print() const {
        std::copy(data, data + size_, std::ostream_iterator<T>(std::cout, " "));
        std::cout << std::endl;
    }
};

template<>
class DataManager<char> {
private:
    static const size_t MAX = 64;
    char data[MAX];
    size_t size_ = 0;

public:
    void push(char c) {
        if (ispunct((unsigned char)c)) {
            c = '_';
        }

        if (size_ >= MAX)
            size_ = 0;

        for (size_t i = size_; i > 0; --i) {
            data[i] = data[i - 1];
        }

        data[0] = c;
        ++size_;
    }

    void push(char elems[], size_t n) {
        for (size_t i = 0; i < n; ++i) {
            push(elems[i]);
        }
    }

    char peek() const {
        if (size_ == 0 || size_ % 2 == 0) {
            return 0;
        }
        return data[size_ / 2];
    }

    char pop() {
        if (size_ == 0) {
            return 0;
        }

        size_t index = (size_ % 2 == 0) ? (size_ / 2 - 1) : (size_ / 2);
        char value = data[index];

        for (size_t i = index; i + 1 < size_; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
        return value;
    }

    char popUpper() {
        char c = pop();
        return std::toupper((unsigned char)c);
    }

    char popLower() {
        char c = pop();
        return std::tolower((unsigned char)c);
    }
};