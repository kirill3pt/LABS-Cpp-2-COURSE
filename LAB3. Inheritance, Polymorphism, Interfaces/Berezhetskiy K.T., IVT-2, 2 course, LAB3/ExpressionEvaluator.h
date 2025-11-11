#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable { //реализация класса ILoggable
protected:
	int count; // количество операндов x1, x2, x3 и т.д.
	double* operands; // массив операндов
public:
	virtual double calculate() const = 0;
	ExpressionEvaluator();
	ExpressionEvaluator(int count);
	virtual ~ExpressionEvaluator();
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
	virtual void logToScreen() const override = 0;
	virtual void logToFile(const std::string& filename) const override = 0;
};