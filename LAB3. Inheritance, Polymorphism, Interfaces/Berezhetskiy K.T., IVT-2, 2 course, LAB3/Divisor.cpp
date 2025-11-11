#include <iostream>
#include "Divisor.h"
#include <algorithm>

Divisor::Divisor(int count) : ExpressionEvaluator(count) {}

double Divisor::calculate() const {
	double result = operands[0];
	for (int i = 0; i < count; i++) {
		if (operands[i] == 0) {
			std::cout << "Ошибка: деление на ноль!\n";
			return 0.0;
		}
		result /= operands[i];
	}
	return result;
}

void Divisor::shuffle() {
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - 1 - i; j++) {
			if (operands[j] > operands[j + 1]) {
				// поменять местами
				double temp = operands[j];
				operands[j] = operands[j + 1];
				operands[j + 1] = temp;
			}
		}
	}
}

void Divisor::shuffle(size_t i, size_t j) {
	if (i >= count || j >= count) {
		return;
	}
	int intPart1 = (int)operands[i];
	double fracPart1 = operands[i] - intPart1;
	if (fracPart1 < 0) {
		fracPart1 = -fracPart1;
	}
	int intPart2 = (int)operands[j];
	double fracPart2 = operands[j] - intPart2;
	if (fracPart2 < 0) {
		fracPart2 = -fracPart2;
	}
	if (fracPart1 > 1e-9 || fracPart2 > 1e-9) {
		double temp = operands[i];
		operands[i] = operands[j];
		operands[j] = temp;
	}
}
void Divisor::logToScreen() const {
	std::cout << operands[0];
	for (int i = 1; i < count; i++) {
		std::cout << " / ";
		if (operands[i] < 0) {
			std::cout << "(" << operands[i] << ")";
		}
		else {
			std::cout << operands[i];
		}
	}
	std::cout << " < Total " << count << " >" << std::endl;
	std::cout << "< Result " << calculate() << " >" << std::endl;
	std::cout << std::endl;
}

void Divisor::logToFile(const std::string& filename) const {
	std::ofstream file(filename, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
		return;
	}
	file << operands[0];
	for (int i = 1; i < count; i++) {
		file << " / ";
		if (operands[i] < 0) {
			file << "(" << operands[i] << ")";
		}
		else {
			file << operands[i];
		}
	}
	file << " < Total " << count << " >\n";
	file << "< Result " << calculate() << " >\n\n";
	file.close();
}