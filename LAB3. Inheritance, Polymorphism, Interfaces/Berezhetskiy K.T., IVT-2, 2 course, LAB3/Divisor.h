#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <iostream>

class Divisor : public ExpressionEvaluator, public IShuffle {
public:
	Divisor(int count);
	double calculate() const override;
	void shuffle() override;                // отсортировать по возрастанию
	void shuffle(size_t i, size_t j) override; // обмен при дробной части
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
};