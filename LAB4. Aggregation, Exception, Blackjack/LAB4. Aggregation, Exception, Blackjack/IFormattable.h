#pragma once
#include <iostream>
#include <string>
class IFormattable {
public:
	virtual ~IFormattable() = default;
	virtual std::string format() const = 0;
};