#include <iostream>
#include "IControllable.h"
#include "Heater.h"
#include <string>

Heater::Heater(std::string firm, std::string model, double weight, int year, int power,
    double temperature, int mode)
    : HouseholdDevice(firm, model, weight, year, power),
    temperature_(temperature), mode_(mode) { }

void Heater::control(int temperature) {
    std::cout << "[Обогреватель]. Получена температура: " << temperature << "\n";

    if (temperature > 45) {
        std::cout << "Температура слишком высокая! Обогреватель выключается.\n";
        mode_ = 0;
        return;
    }

    if (temperature <= 20) {
        mode_ = 1;   // минимальный нагрев
    }
    else if (temperature <= 35) {
        mode_ = 2;   // средний нагрев
    }
    else {
        mode_ = 3;   // максимальный нагрев
    }

    temperature_ = temperature;

    std::cout << "Обогреватель настроен. Новый режим: " << mode_ << "\n";
}

void Heater::print() const
{
    std::cout << "Обогреватель — " << firm_ << " " << model_
        << ", " << weight_ << " кг, "
        << "Год: " << year_ << ", Мощность: " << power_
        << " Вт, Температура: " << temperature_
        << ", Режим: " << mode_
        << "\n";
}