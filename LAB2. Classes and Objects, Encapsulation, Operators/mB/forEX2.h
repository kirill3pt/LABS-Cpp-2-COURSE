#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
	int numerator_;
	int denominator_;
	static int count_;
public:
	Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) { count_++; }
	void print();
	void reduce();
	Fraction operator+(const Fraction& other);
	Fraction operator-(const Fraction& other);
	Fraction operator*(const Fraction& other);
	Fraction operator/(const Fraction& other);
	static int gcd(int n, int m);
	static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);
	static int getCount() { return count_; }
};