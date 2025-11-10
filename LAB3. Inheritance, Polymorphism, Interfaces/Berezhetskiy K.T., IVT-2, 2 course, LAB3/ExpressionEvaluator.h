#pragma once
#include <iostream>
#include <fstream>
#include <string>

class ExpressionEvaluator {
private:
	int n; // количество операндов x1, x2, x3 и т.д.
	int* operands; // массив операндов
public:
	virtual double calculate() = 0;
	ExpressionEvaluator() : n(20) { // конструктор без параметров, 20 значений инициализируется нулями
		operands = new int[n];
		for (int i = 0; i < 20; i++) {
			operands[i] = 0;
		}
	}
	ExpressionEvaluator(int count) : n(count) { // конструктор в кач-ве параметров принимает n операндов и инициализирует их нулями
		operands = new int[n];
		for (int i = 0; i < n; i++) {
			operands[i] = 0;
		}
	}
	virtual ~ExpressionEvaluator() {
		delete[] operands;
	}
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
};