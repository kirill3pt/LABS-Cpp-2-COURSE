#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include "Tasks.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");

    int choice;
    cout << "1 - задание 1;\n2 - задание 2;\n3 - задание 3;  ";
    cin >> choice;
    tasks task;
    switch (choice) {
    case 1: {
        const int n = 16;
        int arr[n];
        int result[n];
        int count;
        task.processArray(arr, result, n, count);
        printf("Вход:[ ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("]\n");
        printf("Выход:[ ");
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("], count = %d\n", count);
        break;
    }
    case 2: {
        const int n = 18;
        int* arr = new int[n];
        task.initArray(arr, n);
        task.print1D(arr, n);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        int row = 9, col = 2;
        int** matrix = task.convert1Dto2D(arr, row, col);
        task.print2D(matrix, row, col);
        delete[] arr;
        for (int i = 0; i < row; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        break;
    }
    case 3: {
        const char src[] = "www.some_address.and_something_else.com!";
        char dest1[100];
        char dest2[100];
        strcpy_s(dest1, src);
        task.my_strcpy(dest2, src);
        printf("Initial string: %s\n", src);
        printf("Standard: %s \n", dest1);
        printf("My version: %s\n", dest2);
        break;
    }
    default:
        cout << "Нет такой программы" << endl;
    }
    return 0;
}
