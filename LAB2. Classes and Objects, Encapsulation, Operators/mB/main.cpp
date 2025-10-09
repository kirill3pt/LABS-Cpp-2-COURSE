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
#include "forEX3.h"

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
    case 3: {
        Conditioner* cond1 = new Conditioner("LG", "CoolX", 14.5, 25.0, "Ожидание", 2022);
        Conditioner* cond2 = new Conditioner("Samsung", "WindPro", 13.0, 23.5, "Ожидание", 2023);
        Conditioner cond3;
        cond3.setFirm("Daikin");
        cond3.setModel("FTXF35");
        cond3.setWeight(12.8);
        cond3.setTemperature(24.0);
        cond3.setMode("Ожидание");
        cond3.setYear(2021);
        double totalChange = 0; 
        int totalCount = 0;
        for (int i = 1; i <= 3; i++) {
            cout << "\n=== Настройка #" << i << " ===" << endl;
            int choice;
            double temp;
            string mode;
            cout << "Выберите режим для всех кондиционеров:\n";
            cout << "1 — Охлаждение\n2 — Нагрев\n3 — Ожидание\n";
            cout << "Ваш выбор: ";
            cin >> choice;

            if (choice == 1) {
                mode = "Охлаждение";
                cout << "На сколько градусов охладить: ";
                cin >> temp;
            }
            else if (choice == 2) {
                mode = "Нагрев";
                cout << "На сколько градусов нагреть: ";
                cin >> temp;
            }
            else {
                mode = "Ожидание";
                temp = 0;
            }
            cond1->settings(mode, temp);
            cond2->settings(mode, temp);
            cond3.settings(mode, temp);
            if (temp != 0) {
                totalChange += temp;
                totalCount++;
            }
        }
        cout << "\n=== Итоговая информация ===\n";
        cond1->print();
        cond2->print();
        cond3.print();
        double avgChange = (totalCount > 0) ? totalChange / totalCount : 0;
        cout << "Среднее изменение температуры за период: " << avgChange << " градусов\n";
        cond1->serialize("cond1.txt");
        cond2->serialize("cond2.txt");
        cond3.serialize("cond3.txt");
        //cond3.serialize();
        cout << "\nДанные сохранены в файлы cond1.txt, cond2.txt, cond3.txt\n";
        /*Conditioner test;
        test.deserialize("cond1.txt");
        cout << "\nПроверка чтения из файла:\n";
        test.print();*/
        delete cond1;
        delete cond2;
    }
    }
    return 0;
}
