#include <iostream>
#include "IControllable.h"
#include "Conditioner.h"
#include <string>

Conditioner::Conditioner(std::string firm, std::string model, double weight, int year, int power, double temperature, int mode)
    : HouseholdDevice(firm, model, weight, year, power), temperature_(temperature), mode_(mode){ }

void Conditioner::control(int temperature) {
    if (temperature < 10)
    {
        std::cout << "Температура слишком низкая! Кондиционер выключается.\n";
        mode_ = 0;
        return;
    }
    if (temperature > 10) {
        mode_ = 1;
    }
    else if (temperature > 20) {
        mode_ = 2;
    }
    else {
        mode_ = 3;
    }
    std::cout << "Обогреватель настроен. Новый режим: " << mode_ << "\n";
}
void Conditioner::print() const
{
    std::cout << "Кондиционер — " << firm_ << " " << model_
        << ", " << weight_ << " кг, "
        << "Год: " << year_ << ", Мощность: " << power_
        << "Вт, Темп: " << temperature_
        << ", Режим: " << mode_
        << "\n";
}