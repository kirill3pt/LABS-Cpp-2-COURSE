#include <iostream>
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "ILoggable.h"
#include "Divisor.h"
#include "Multiplier.h"
#include "IShuffle.h"

int main() {
	setlocale(LC_ALL, "rus");
	int choice;
	std::cout << "Введите № задания:\n1 - Задание №1; ";
	std::cin >> choice;
	switch (choice) {
	case 1: {
		/* Создать массив указателей на абстрактный класс обработки арифметических выражений.*/
		ExpressionEvaluator* evaluators[3];
		/* создать объект первого типа (CustomExpressionEvaluator) (result = x1 + x2 * x3 + x4 * х5 + ...)
		и заполнить его данными вторым способом (присвоить группой)*/
		evaluators[0] = new CustomExpressionEvaluator(5);
		double custom_operands[] = { 5, 16, -3, 10, 12 };
		evaluators[0]->setOperands(custom_operands, 5); /* должно вычисляться 5 + 16 * (-3) * 10 + 12 = 77
		создание объекта второго типа (Multiplier) (х1 * х2 * х3 * х4 * ...)
		и заполнить его данными вторым способом*/
		// должно вычисляться 1.5 * 4 * (-2.5) * (-8) * (-15) = -1800
		evaluators[1] = new Multiplier(5);
		double multiplier_operands[] = { 1.5, 4, -2.5, -8, -15 };
		evaluators[1]->setOperands(multiplier_operands, 5);
		/* создание объекта третьего типа (Divisor) (х1 / х2 / х3 / х4 * ...)
		и заполнить его данными первым способом(поэлементно)*/
		evaluators[2] = new Divisor(4);
		evaluators[2]->setOperand(0, 150);
		evaluators[2]->setOperand(1, -3);
		evaluators[2]->setOperand(2, 10);
		evaluators[2]->setOperand(3, -2.5);
		/* проход в цикле по указателям evaluators
		и вывод на консоль и в файл лога выражения (в консоли еще сам результат выражения)*/
		for (size_t i = 0; i < 3; ++i) // демонстрация полиморфизма
		{
			evaluators[i]->logToFile("Lab3.log");
			evaluators[i]->logToScreen();
			std::cout << evaluators[i]->calculate() << std::endl;
			std::cout << std::endl;
		}
		/* здесь организовать еще цикл по указателям evaluators, в теле которого
		 проверить тип текущего объекта, и если он реализует интерфейс IShuffle,
		 то вызвать метод shuffle() этого объекта, после чего метод calculate()
		 и затем отобразить на экране результат перемешивания и вычисления выражения */
		for (int i = 0; i < 3; i++) {
			std::cout << "Выражение " << i + 1 << ":\n";
			evaluators[i]->logToScreen();
			IShuffle* shuffle = dynamic_cast<IShuffle*>(evaluators[i]);
			if (shuffle) {
				std::cout << "Объект " << i + 1 << " реализует интерфейс IShuffle\n";
				shuffle->shuffle();
				std::cout << "После shuffle():\n";
				evaluators[i]->logToScreen();
				evaluators[i]->logToFile("Lab3.log");
				if (i == 1) {
					shuffle->shuffle(0, 3);
					std::cout << "После shuffle(size_t i = 0, size_t j = 3):\n";
					evaluators[i]->logToScreen();
					evaluators[i]->logToFile("Lab3.log");
				}
			}
			else {
				std::cout << "Объект " << i + 1 << " не реализует интерфейс IShuffle\n";
			}
		}
	}
		  return 0;
	}
}