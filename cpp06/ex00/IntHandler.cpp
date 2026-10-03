#include "IntHandler.hpp"
#include "utils.hpp"
#include "iomanip"

IntHandler::IntHandler(void) : Handler() {}

IntHandler::IntHandler(const IntHandler& other) : Handler(other) {}

IntHandler& IntHandler::operator=(const IntHandler& other) {
	Handler::operator=(other);
	return (*this);
}


void IntHandler::handle(const std::string& str) {
	if (str.find_first_not_of("+-0123456789") == std::string::npos) {
		std::stringstream ss;	
		int num;
		char c = 0;
		ss << str;
		if (ss >> num && !(ss >> c)) {
			std::cout << std::fixed << std::setprecision(1);
			printChar(num);
			std::cout << "int: " << (num) << "\n";
			std::cout << "float: " << static_cast<float>(num) << "f\n";
			std::cout << "double: " << static_cast<double>(num) << "\n";
			return ;
		}
		else {
			goto nextHandler; 
		}
	}
	else {
		goto nextHandler;
	}

nextHandler:
	if (m_nextHandler) {
		m_nextHandler->handle(str);
	}

}

IntHandler::~IntHandler(void) {}
