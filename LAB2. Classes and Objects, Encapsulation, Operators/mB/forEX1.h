#pragma once
#include <iostream>
using namespace std;

class Vector {
private:
    int* data_; // ��������� �� ������
    int size_; // ������ �������

public:
    Vector(int n); // �����������               
    void initArray();
    void print1D(); // ����� ���������
    ~Vector(); // ����������
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
    int** data_; // ��������� ������������ ������
    int rows_;
    int cols_;
public:
    Matrix(int r, int c);       // �����������
    ~Matrix();                  // ����������

    void convert1Dto2D(const int* arr, int totalSize);
    void print2D();
    int at(int i, int j) const;        // �������� ��������
    void setAt(int i, int j, int val); // ���������� ��������
    Matrix& operator++();     // ++m
    Matrix operator++(int);   // m++
    Matrix& operator--();     // --m
    Matrix operator--(int);   // m--
};