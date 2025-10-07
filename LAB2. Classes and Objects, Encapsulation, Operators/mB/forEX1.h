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
    Vector& operator++();     // ������� ++v
    Vector operator++(int);   // �������� v++
    Vector& operator--();     // ������� --v
    Vector operator--(int);   // �������� v--
};

class Matrix {
private:
    int** data_; // ��������� ������������ ������
    int rows_;
    int cols_;
public:
    Matrix(int r, int c);       // �����������
    ~Matrix();                  // ����������

    int at(int i, int j) const;        // �������� ��������
    void setAt(int i, int j, int val); // ���������� ��������
    void print() const;                // ������
};