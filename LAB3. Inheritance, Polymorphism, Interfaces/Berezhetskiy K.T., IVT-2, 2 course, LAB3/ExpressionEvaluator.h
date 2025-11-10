#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable { //реализация класса ILoggable
private:
	int n; // количество операндов x1, x2, x3 и т.д.
	int* operands; // массив операндов
public:
	virtual double calculate() = 0;
	ExpressionEvaluator();
	ExpressionEvaluator(int count);
	virtual ~ExpressionEvaluator();
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
};