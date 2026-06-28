#pragma once

#include <iostream>
#include <string>

void color(const std::string color) {
	std::cout << "\033[" + color + "m";
}
