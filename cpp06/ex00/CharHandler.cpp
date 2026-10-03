#include "CharHandler.hpp"
#include "utils.hpp"
#include <cctype>
#include <limits>
#include <iomanip>

CharHandler::CharHandler(void) : Handler() {
}

CharHandler::CharHandler(const CharHandler& other) : Handler(other) {
}

CharHandler& CharHandler::operator=(const CharHandler& other) {
	Handler::operator=(other);
  return (*this);
}


void CharHandler::handle(const std::string& str) {
	if (str.length() == 1) {
		char c = str.at(0);
		if (!std::isdigit(c))
		{
			std::cout << std::fixed << std::setprecision(1);
			printChar(c);
			std::cout << "int: " << static_cast<int>(c) << "\n";
			std::cout << "float: " << static_cast<float>(c) << "f\n";
			std::cout << "double: " << static_cast<double>(c) << "\n";

			return ;
		}
	}
	if (m_nextHandler) {
		m_nextHandler->handle(str);
	}
}

CharHandler::~CharHandler(void) {}
