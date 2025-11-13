#include <iostream>
#include "Divisor.h"

Divisor::Divisor(int count) : ExpressionEvaluator(count) {}

double Divisor::calculate() const {
	double result = operands[0];
	for (int i = 1; i < count; i++) {
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
	for (int i = 0; i < count; i++) {
		if (operands[i] < 0) {
			std::cout << "(" << operands[i] << ")";
		}
		else {
			std::cout << operands[i];
		}
		if (i != count - 1) {
			std::cout << " / ";
		}
	}
	std::cout << " < Total " << count << " >" << std::endl;
	std::cout << "< Result " << calculate() << " >" << std::endl;
	std::cout << std::endl;
}

void Divisor::logToFile(const std::string& filename) const {
	std::ofstream log(filename, std::ios::app | std::ios_base::out);
	for (int i = 0; i < count; i++) {
		if (operands[i] < 0) {
			log << "(" << operands[i] << ")";
		}
		else {
			log << operands[i];
		}
		log << " / ";
	}
	log << " < Total " << count << " >\n";
	log << "< Result " << calculate() << " >\n\n";
	log.close();
}