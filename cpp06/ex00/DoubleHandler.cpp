#include "DoubleHandler.hpp"

DoubleHandler::DoubleHandler(void) : Handler() {}

DoubleHandler::DoubleHandler(const DoubleHandler& other) : Handler(other) {}

DoubleHandler& DoubleHandler::operator=(const DoubleHandler& other) {
	Handler::operator=(other);
	return (*this);
}

// TODO:dont forget precision

void DoubleHandler::handle(const std::string& str) {
	if (str == "-inf" || str == "+inf")	 {
		std::cout << "char: " << "impossible\n";
		std::cout << "int: " << "impossible\n";
		std::cout << "float: " << str.at(0) << "inff"  << "\n";
		std::cout << "double: " << str << "\n";
	}
	else if (str == "nan") {
		std::cout << "char: " << "impossible\n";
		std::cout << "int: " << "impossible\n";
		std::cout << "float: " << "nanf" << "\n";
		std::cout << "double: " << str << "\n";
	}
	else {
		if (str.find_first_not_of("0123456789-+.") != std::string::npos) 
			goto nextHandler;

		char *ptr;
		double num;
		num = std::strtod(str.c_str(), &ptr);
		if (*ptr != '\0' || errno == ERANGE)
			goto nextHandler;
		printChar(num);
		printInt(num);
		printFloat(num);
		std::cout << "ldouble: " << num << "\n";
	}
	return ;
nextHandler:
	// no next handler sadly
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible" << "\n";
		std::cout << "double: impossible" << "\n";
}

DoubleHandler::~DoubleHandler(void) {}
