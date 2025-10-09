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
    cout << "�������� �������:\n1 - ������� �1;\n2 - ������� �2;\n3 - ������� �3: ";
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
            
            cout << "\n������� ����������� ��������: *, /, +, -: " << endl
                << "��� �������� ����� �� ������������ ����� � ���������� - ������� 1; " << endl
                << "��� �������� �� ���������� ����� � ������������ - ������� 2; " << endl
                << "��� ���������� ����� - ������� 3; " << endl
                << "��� ������ - ������� 0; " << endl
                << "\n����: ";
            cin >> operation;
            if (operation == '*' || operation == '/' || operation == '+' || operation == '-') {
                cout << "������� ��������� 1 �����: "; cin >> x0;
                cout << "������� ����������� 1 ����� (0 � ������): "; cin >> y0;
                if (y0 == 0) {
                    break;
                }
                cout << "������� ��������� 2 �����: "; cin >> x1;
                cout << "������� ����������� 2 ����� (0 - ������): "; cin >> y1;
                if (y1 == 0) {
                    break;
                }

                Fraction f1(x0, y0);
                Fraction f2(x1, y1);

                if (operation == '*') {
                    cout << "\n��������� ��������� = ";
                    (f1 * f2).print();
                }
                if (operation == '/') {
                    cout << "\n��������� ������� = ";
                    (f1 / f2).print();
                }
                if (operation == '+') {
                    cout << "\n��������� �������� = ";
                    (f1 + f2).print();
                }
                if (operation == '-') {
                    cout << "\n��������� ��������� = ";
                    (f1 - f2).print();
                }
            }
            else if (operation == '1') {
                cout << "������� ���������: "; cin >> x0;
                cout << "������� ����������� (0 � ������): "; cin >> y0;
                if (y0 == 0) {
                    break;
                }
                Fraction f(x0, y0);
                double result = static_cast<double>(x0) / y0;
                cout << "\n���������� �����: " << result << endl;
            }
            else if (operation == '2') {
                double num;
                cout << "������� ���������� �����: ";
                cin >> num;
                cout << "\n������������ �����: ";
                Fraction::printAsFraction(num);
            }
            else if (operation == '3') {
                cout << "������� ���������: "; cin >> x0;
                cout << "������� ����������� (0 � �����): "; cin >> y0;
                if (y0 == 0) break;
                Fraction f(x0, y0);
                cout << "�� ����������: ";
                f.print();
                f.reduce();
                cout << "\n����� ����������: ";
                f.print();
            }
            else if (operation == '0') {
                break;
            }
            cout << "�ר���� ���� ������: " << Fraction::getCount() << "\n";
        } while (true);
        break;
    }
    }
    return 0;
}
