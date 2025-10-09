#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include "forEX1.h"
#include "forEX2.h"

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "rus");
    int choice;
    cout << "Выберите задание:\n1 - задание №1;\n2 - задание №2;\n3 - задание №3: ";
    cin >> choice;
    switch (choice)
    {
    case 1: {
        Vector v(18);
        const int n = 18;
        v.initArray();
        v.print1D();
        Matrix m(9, 2);
        int* arr = v.getData();
        for (int i = 0; i < n - 1; i++) {
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
        break;
    }
    case 2: {
        int x0, y0, x1, y1;
        char operation;
        do {
            
            cout << "\nВведите необходимую операцию: *, /, +, -: " << endl
                << "Для перевода числа из обыкновенной дроби в десятичную - введите 1; " << endl
                << "Для перевода из десятичной дроби в обыкновенную - введите 2; " << endl
                << "Для сокращения дроби - введите 3; " << endl
                << "Для выхода - введите 0; " << endl
                << "\nВвод: ";
            cin >> operation;
            if (operation == '*' || operation == '/' || operation == '+' || operation == '-') {
                cout << "Введите числитель 1 дроби: "; cin >> x0;
                cout << "Введите знаменатель 1 дроби (0 — нельзя): "; cin >> y0;
                if (y0 == 0) {
                    break;
                }
                cout << "Введите числитель 2 дроби: "; cin >> x1;
                cout << "Введите знаменатель 2 дроби (0 - нельзя): "; cin >> y1;
                if (y1 == 0) {
                    break;
                }

                Fraction f1(x0, y0);
                Fraction f2(x1, y1);

                if (operation == '*') {
                    cout << "\nРезультат умножения = ";
                    (f1 * f2).print();
                }
                if (operation == '/') {
                    cout << "\nРезультат деления = ";
                    (f1 / f2).print();
                }
                if (operation == '+') {
                    cout << "\nРезультат сложения = ";
                    (f1 + f2).print();
                }
                if (operation == '-') {
                    cout << "\nРезультат вычитания = ";
                    (f1 - f2).print();
                }
            }
            else if (operation == '1') {
                cout << "Введите числитель: "; cin >> x0;
                cout << "Введите знаменатель (0 — нельзя): "; cin >> y0;
                if (y0 == 0) {
                    break;
                }
                Fraction f(x0, y0);
                double result = static_cast<double>(x0) / y0;
                cout << "\nДесятичная форма: " << result << endl;
            }
            else if (operation == '2') {
                double num;
                cout << "Введите десятичное число: ";
                cin >> num;
                cout << "\nОбыкновенная дробь: ";
                Fraction::printAsFraction(num);
            }
            else if (operation == '3') {
                cout << "Введите числитель: "; cin >> x0;
                cout << "Введите знаменатель (0 — выход): "; cin >> y0;
                if (y0 == 0) break;
                Fraction f(x0, y0);
                cout << "До сокращения: ";
                f.print();
                f.reduce();
                cout << "\nПосле сокращения: ";
                f.print();
            }
            else if (operation == '0') {
                break;
            }
            cout << "СЧЁТЧИК ВСЕХ ДРОБЕЙ: " << Fraction::getCount() << "\n";
        } while (true);
        break;
    }
    }
    return 0;
}
