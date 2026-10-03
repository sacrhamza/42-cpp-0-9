#include<iostream>
#include"Base.hpp"
#include"utils.hpp"
#include <ctime>

int main(void) {

	std::srand(std::time(NULL));

	Base* var = generate();
	identify(var);
	identify(*var);
	delete var;

	Base* var1 = generate();
	identify(var1);
	identify(*var1);
	delete var1;
	return (0);
}
