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
        v.initArray();
        v.print1D();
        ++v;
        v.print1D();
    }
    return 0;
}
