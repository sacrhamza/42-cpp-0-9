#include "utils.hpp"

void printInt(double num) {
	if (num > std::numeric_limits<int>::max() ||
			num < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible\n";
	}
	else {
		std::cout << "int: " << static_cast<int>(num) << "\n";
	}
}


void printChar(double num) {
	if (num > std::numeric_limits<char>::max() ||
			num < std::numeric_limits<char>::min()) {
		std::cout << "char: impossible\n";
	}
	else {
		char c = static_cast<char>(num);
		if (std::isprint(c))
			std::cout << "char: '"  << c << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}
}

void printFloat(double num) {
	if (num > std::numeric_limits<float>::max() ||
			num < std::numeric_limits<float>::min()) {
		std::cout << "float: impossible\n";
	}
	else {
		std::cout << "float: " << static_cast<float>(num) << "f\n";
	}
}


