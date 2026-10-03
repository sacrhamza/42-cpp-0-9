#include "FloatHandler.hpp"


FloatHandler::FloatHandler(void) : Handler() {}

FloatHandler::FloatHandler(const FloatHandler& other) : Handler(other) {}

FloatHandler& FloatHandler::operator=(const FloatHandler& other) {
	Handler::operator=(other);
	return (*this);
}

void FloatHandler::handle(const std::string& str) {
	if (str == "-inff" || str == "+inff")	 {
		std::cout << "char: " << "impossible\n";
		std::cout << "int: " << "impossible\n";
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str.at(0) << "inf"  << "\n";
	}
	else if (str == "nanf") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << str << "\n";
		std::cout << "double: nan" << "\n";
	}
	else {
		if (str.find_first_not_of("0123456789-+.f") != std::string::npos) 
			goto nextHandler;
		if (str.find('.') == std::string::npos)
			goto  nextHandler;

		char *ptr;
		float num;
		if (str.at(str.length() - 1) != 'f')
			goto nextHandler;
		num = std::strtof(str.c_str(), &ptr);
		if (ptr != &str[str.length() - 1] || errno == ERANGE)
			goto nextHandler;

		std::cout << std::fixed << std::setprecision(7);
		printChar(num);
		printInt(num);
		std::cout << "float: " << num << "f\n";
		std::cout << "double: " << static_cast<double>(num) << "\n";
	}
	return ;
nextHandler:
	if (m_nextHandler) {
		m_nextHandler->handle(str);
	}
}

FloatHandler::~FloatHandler(void) {}
