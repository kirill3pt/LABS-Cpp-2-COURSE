#include <iostream>
#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() : n(20) { // конструктор без параметров, 20 значений инициализируется нулями
	operands = new int[n];
	for (int i = 0; i < 20; i++) {
		operands[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int count) : n(count) { // конструктор в кач-ве параметров принимает n операндов и инициализирует их нулями
	operands = new int[n];
	for (int i = 0; i < n; i++) {
		operands[i] = 0;
	}
}

ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] operands;
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {

}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {

}