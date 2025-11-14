#include <iostream>
#include "IControllable.h"
#include "Conditioner.h"
#include <string>

Conditioner::Conditioner(std::string firm, std::string model, double weight, int year, int power, double temperature, int mode)
    : HouseholdDevice(firm, model, weight, year, power), temperature_(temperature), mode_(mode){ }

void Conditioner::control(int temperature) {
    std::cout << "[Кондиционер]. Получена температура: " << temperature << "\n";

    if (temperature < 10) {
        std::cout << "Температура слишком низкая! Кондиционер выключается.\n";
        mode_ = 0;
        return;
    }
    if (temperature <= 18) {
        mode_ = 1;
    }
    else if (temperature <= 25) {
        mode_ = 2;
    }
    else {
        mode_ = 3;
    }

    temperature_ = temperature;

    std::cout << "Кондиционер настроен. Новый режим: " << mode_ << "\n";
}
void Conditioner::print() const
{
    std::cout << "Кондиционер — " << firm_ << " " << model_
        << ", " << weight_ << " кг, "
        << "Год: " << year_ << ", Мощность: " << power_
        << " Вт, Температура: " << temperature_
        << ", Режим: " << mode_
        << "\n";
}