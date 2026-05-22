#include "ScalarConverter.hpp"
#include "sstream"

void ScalarConverter::convert(std::string rep) {
	char character;
	std::stringstream stream(rep);
	stream >> character;
	if (stream.fail() ||  stream.eof())
		std::cout << "error\n";
	std::string line;
	// getline(stream, line);
	// stream >> line;
	std::cout << "char: " <<  character << "\n";
	std::cout << "remaining: "<< stream.str() << "\n";
	std::cout << "line: "<< line << "\n";
	std::cout << "reached: "<< stream.tellg() << "\n";
}
