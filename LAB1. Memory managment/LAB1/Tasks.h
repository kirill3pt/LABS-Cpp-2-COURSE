#pragma once
#include <iostream>
using namespace std;

class tasks {
public:
    int processArray(int arr[], int result[], int n, int& count);
    int initArray(int* arr, int n);
    int print1D(int* arr, int n);
    int** convert1Dto2D(int* arr, int row, int col);
    int print2D(int** matrix, int rows, int cols);
    char* my_strcpy(char* dest, const char* src);
};