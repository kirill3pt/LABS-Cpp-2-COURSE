#include <iostream>
#include "CustomExpressionEvaluator.h"

CustomExpressionEvaluator::CustomExpressionEvaluator(int count) : ExpressionEvaluator(count) {}

double CustomExpressionEvaluator::calculate() const {
	double result = operands[0];
	for (int i = 1; i + 1 < count; i += 2) {
		result += operands[i] * operands[i + 1];
	}
	return result;
}
void CustomExpressionEvaluator::logToScreen() const {
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

void CustomExpressionEvaluator::logToFile(const std::string& filename) const {
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