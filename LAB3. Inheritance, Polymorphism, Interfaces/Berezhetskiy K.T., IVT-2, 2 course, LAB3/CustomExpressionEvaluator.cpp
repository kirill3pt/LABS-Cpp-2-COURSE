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
    std::ofstream log(filename, std::ios::app | std::ios_base::out);
    log << "Log Record\n";
    log << operands[0];
    for (int i = 1; i + 1 < count; i += 2) {
        log << " + ";
        if (operands[i] < 0) {
            log << "(" << operands[i] << ")";
        }
        else {
            log << operands[i];
        }
        log << " * ";
        if (operands[i + 1] < 0) {
            log << "(" << operands[i + 1] << ")";
        }
        else {
            log << operands[i + 1];
        }
    }
    if (count % 2 == 0) {
        log << " + " << operands[count - 1];
    }
    log << " < Total " << count << " >\n";
    log << "< Result " << calculate() << " >\n\n";
    log.close();
}