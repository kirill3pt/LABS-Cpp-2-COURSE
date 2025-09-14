#include <stdio.h>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include "Tasks.h"

using namespace std;

int tasks::initArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * i + 1;
        if (i % 2 != 0) {
            arr[i] *= -1;
        }
    }
    return 0;
}

int tasks::print1D(int* arr, int n) {
    cout << '[';
    for (int i = 0; i < n; i++) {
        cout << setw(5) << arr[i];
    }
    cout << setw(5) << ']';
    cout << '\n' << endl;
    return 0;
}

int** tasks::convert1Dto2D(int* arr, int row, int col) {
    int** matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = arr[k++];
        }
    }
    return matrix;
}

int tasks::print2D(int** matrix, int row, int col) {
    cout << "=>" << '\n' << endl;
    for (int i = 0; i < row; i++) {
        if (i == 0) {
            cout << "[ ";
        }
        else {
        cout << "  ";   
        }
        for (int j = 0; j < col; j++) {
            cout << setw(5) << matrix[i][j];
        }
        if (i == row - 1) {
            cout << " ]";
        }
        cout << endl;
    }
    return 0;
}