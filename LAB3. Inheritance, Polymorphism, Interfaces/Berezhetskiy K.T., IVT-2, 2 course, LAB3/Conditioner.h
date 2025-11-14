#pragma once
#include "HouseholdDevice.h"
#include "IControllable.h"
#include <string>
#include <iostream>

class Conditioner : public HouseholdDevice, public IControllable {
protected:
	double temperature_;
	int mode_;
public:
	Conditioner(std::string firm, std::string model, double weight, int year, int power, double temperature, int mode = 0);
	void control(int temperature) override;
	void print() const override;
};