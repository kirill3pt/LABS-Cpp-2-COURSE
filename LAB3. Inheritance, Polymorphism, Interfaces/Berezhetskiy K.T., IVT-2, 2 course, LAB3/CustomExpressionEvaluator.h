#pragma once
#include "ExpressionEvaluator.h"
#include <iostream>

class CustomExpressionEvaluator : public ExpressionEvaluator{
public:
	CustomExpressionEvaluator(int count);
	double calculate() const override;
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
};