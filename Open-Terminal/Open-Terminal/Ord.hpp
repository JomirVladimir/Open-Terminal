#pragma once

#include <string>

int ord(std::string txt) {
	int sum = 0;
	for (char chr : txt) {
		sum += int(chr);
	}
	return sum;
}
