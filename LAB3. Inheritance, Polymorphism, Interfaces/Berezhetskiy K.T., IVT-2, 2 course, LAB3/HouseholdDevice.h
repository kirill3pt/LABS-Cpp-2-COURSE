#pragma once
#include <iostream>
#include <string>

class HouseholdDevice {
protected:
	std::string firm_;
	std::string model_;
	double weight_;
	int year_;
	int power_;
public:
	HouseholdDevice(std::string firm = " ", std::string model = "", double weight = 0, int year = 0, int power = 0):
	firm_(firm), model_(model), weight_(weight), year_(year), power_(power) {}
	virtual void print() const = 0;
	virtual ~HouseholdDevice() {}
};