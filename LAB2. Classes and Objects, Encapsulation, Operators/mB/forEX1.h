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
    Vector& operator++();     // ++v
    Vector operator++(int);   // v++
    Vector& operator--();     // --v
    Vector operator--(int);   // v--
    int* getData() {
        return data_;
    }
};

class Matrix {
private:
    int** data_; // двумерный динамический массив
    int rows_;
    int cols_;
public:
    Matrix(int r, int c);       // конструктор
    ~Matrix();                  // деструктор

    void convert1Dto2D(const int* arr, int totalSize);
    void print2D();
    int at(int i, int j) const;        // получить значение
    void setAt(int i, int j, int val); // установить значение
    Matrix& operator++();     // ++m
    Matrix operator++(int);   // m++
    Matrix& operator--();     // --m
    Matrix operator--(int);   // m--
};