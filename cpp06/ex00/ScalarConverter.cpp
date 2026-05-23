#include "ScalarConverter.hpp"
#include <sstream>

void ScalarConverter::convert(std::string rep) {
	rep = "1200";
	std::stringstream ss(rep);
	float numf;
	ss >> numf;
	if (ss.fail())
		std::cerr << "error";
	std::cout << numf;
	std::cout << ss.gcount();
}
