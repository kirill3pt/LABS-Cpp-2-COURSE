#pragma once
#pragma once
#include <iostream>
#include "IFormattable.h"

inline void prettyPrint(const IFormattable& object) {
    std::cout << object.format() << std::endl;
}