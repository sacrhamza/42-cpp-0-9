#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string rep) {

	CharHandler char_handler;
	 IntHandler int_handler;
	 FloatHandler float_handler;
	 DoubleHandler double_handler;

	 char_handler.setNextHandler(&int_handler);
	 int_handler.setNextHandler(&float_handler);
	 float_handler.setNextHandler(&double_handler);


	char_handler.handle(rep);
}
