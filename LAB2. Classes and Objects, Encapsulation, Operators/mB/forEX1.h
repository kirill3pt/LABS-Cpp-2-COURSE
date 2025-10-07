#pragma once
#include <iostream>
using namespace std;

class Vector {
private:
    int* data_; // указатель на массив
    int size_; // размер массива

public:
    Vector(int n); // конструктор               
    void initArray();
    void print1D(); // вывод элементов
    ~Vector(); // деструктор
    int& operator[](int index);
    Vector& operator++();     // префикс ++v
    Vector operator++(int);   // постфикс v++
    Vector& operator--();     // префикс --v
    Vector operator--(int);   // постфикс v--
};

class Matrix {
private:
    int** data_; // двумерный динамический массив
    int rows_;
    int cols_;
public:
    Matrix(int r, int c);       // конструктор
    ~Matrix();                  // деструктор

    int at(int i, int j) const;        // получить значение
    void setAt(int i, int j, int val); // установить значение
    void print() const;                // печать
};