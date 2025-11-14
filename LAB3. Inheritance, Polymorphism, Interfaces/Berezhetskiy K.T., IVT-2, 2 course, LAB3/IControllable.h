#pragma once
#include <iostream>

class IControllable {
protected:
	int temperature;
public:
	virtual void control(int temperature) = 0;
	virtual ~IControllable(){}
};