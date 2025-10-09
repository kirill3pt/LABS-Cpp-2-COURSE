#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include "forEX2.h"
int Fraction::count_ = 0;
void Fraction::print() {
	cout << numerator_ << '/' << denominator_ << endl;
}

int Fraction::gcd(int n, int m) {
	while (m!= 0) {
		int temp = m;
		m = n % m;
		n = temp;
	}
	return n;
}
void Fraction::reduce() {
	int g = gcd(numerator_, denominator_);
	if (denominator_ < 0) {
		numerator_ = -numerator_;
		denominator_ = -denominator_;
	}
	else {
		numerator_ /= g;
		denominator_ /= g;
	}
}
Fraction Fraction::operator+(const Fraction& other) {
    int n = numerator_ * other.denominator_ + other.numerator_ * denominator_;
    int d = denominator_ * other.denominator_;
    Fraction result(n, d);
    result.reduce();
    return result;
}

Fraction Fraction::operator-(const Fraction& other) {
    int n = numerator_ * other.denominator_ - other.numerator_ * denominator_;
    int d = denominator_ * other.denominator_;
    Fraction result(n, d);
    result.reduce();
    return result;
}

Fraction Fraction::operator*(const Fraction& other) {
    int n = numerator_ * other.numerator_;
    int d = denominator_ * other.denominator_;
    Fraction result(n, d);
    result.reduce();
    return result;
}

Fraction Fraction::operator/(const Fraction& other) {
    int n = numerator_ * other.denominator_;
    int d = denominator_ * other.numerator_;
    Fraction result(n, d);
    result.reduce();
    return result;
}
void Fraction::printAsFraction(double decimal_fraction) {
    int y = 1; // знаменатель
    while (decimal_fraction - int(decimal_fraction) > 1e-9) { // пока есть дробная часть
        decimal_fraction *= 10;
        y *= 10;
    }
    int num = static_cast<int>(decimal_fraction);
    Fraction f(num, y);
    f.reduce();
    f.print();
}

void Fraction::printAsFraction(char* decimal_fraction) {
    double x = atof(decimal_fraction); // переводим строку в число
    int y = 1;            // знаменатель

    while (x - int(x) > 1e-9) { // пока есть дробная часть
        x *= 10;
        y *= 10;
    }

    int n = static_cast<int>(x);
    Fraction f(n, y);
    f.reduce();
    f.print();
}