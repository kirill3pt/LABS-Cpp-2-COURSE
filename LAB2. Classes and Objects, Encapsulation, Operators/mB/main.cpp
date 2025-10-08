#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include "forEX1.h"

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int choice;
    cout << "Выберите задание:\n1 - задание №1;\n2 - задание №2;\n3 - задание №3: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Vector v(18);
        const int n = 18;
        v.initArray();
        v.print1D();
        Matrix m(9, 2);
        int* arr = v.getData();
        for (int i = 0; i < n - 1; i++) { //сортировка пузырьком по убыванию, так же требовалось в 1 лабораторной
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        m.convert1Dto2D(arr, n);
        m.print2D();
    }
    return 0;
}
