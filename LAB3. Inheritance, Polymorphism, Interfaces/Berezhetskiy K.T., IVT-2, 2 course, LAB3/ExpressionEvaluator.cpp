#include <iostream>
#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() : count(20) { // конструктор без параметров, 20 значений инициализируется нулями
	operands = new double[count];
	for (int i = 0; i < 20; i++) {
		operands[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int count) : count(count) { // конструктор в кач-ве параметров принимает n операндов и инициализирует их нулями
	operands = new double[count];
	for (int i = 0; i < count; i++) {
		operands[i] = 0.0;
	}
}

ExpressionEvaluator::~ExpressionEvaluator() { // деструктор
	delete[] operands;
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {
	if (pos < count) { // проверяем выход за границы
		operands[pos] = value; // присваиваем значение value одному операнду на позиции pos
	}
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (size_t i = 0; i < n; i++) { // проход по массиву
		operands[i] = ops[i]; // ставим текущее значение в позицию
	}
}

void ExpressionEvaluator::logToScreen() const {
	std::cout << operands[0];
	for (int i = 1; i + 1 < count; i += 2) {
		std::cout << " + ";
		if (operands[i] < 0) {
			std::cout << "(" << operands[i] << ")";
		}
		else {
			std::cout << operands[i];
		}
		std::cout << " * ";
		if (operands[i + 1] < 0) {
			std::cout << "(" << operands[i + 1] << ")";
		}
		else {
			std::cout << operands[i + 1];
		}
	}
	if (count % 2 == 0) {
		std::cout << " + " << operands[count - 1];
	}
	std::cout << " < Total " << count << " >" << std::endl;
	std::cout << "< Result " << calculate() << " >" << std::endl;
	std::cout << std::endl;
}

void ExpressionEvaluator::logToFile(const std::string& filename) const {
	std::ofstream file(filename, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
		return;
	}
	file << operands[0];
	for (int i = 1; i + 1 < count; i += 2) {
		file << " + ";
		if (operands[i] < 0) {
			file << "(" << operands[i] << ")";
		}
		else {
			file << operands[i];
		}
		file << " * ";
		if (operands[i + 1] < 0) {
			file << "(" << operands[i + 1] << ")";
		}
		else {
			file << operands[i + 1];
		}
	}
	if (count % 2 == 0) {
		file << " + " << operands[count - 1];
	}
	file << " < Total " << count << " >\n";
	file << "< Result " << calculate() << " >\n\n";
	file.close();
}