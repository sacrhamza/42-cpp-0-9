#ifndef _SCALARCONVERTER_H
#define _SCALARCONVERTER_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "IntHandler.hpp"
#include "CharHandler.hpp"
#include "FloatHandler.hpp"
#include "DoubleHandler.hpp"


class ScalarConverter {
	private:
		ScalarConverter();
	public:
		static void convert(std::string rep);
};

#endif
