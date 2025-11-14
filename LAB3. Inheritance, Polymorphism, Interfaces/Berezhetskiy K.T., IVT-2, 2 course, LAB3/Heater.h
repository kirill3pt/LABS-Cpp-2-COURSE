#pragma once
#include <iostream>
#include "IControllable.h"
#include "HouseholdDevice.h"
#include <string>

class Heater : public HouseholdDevice, public IControllable {
protected:
	double temperature_;
	int mode_;
public:
	Heater(std::string firm, std::string model, double weight, int year, int power, double temperature, int mode = 0);
	void control(int temperature) override;
	void print() const override;
};