#include<iostream>
#include"Base.hpp"
#include"utils.hpp"

int main(void) {

	Base* var = genereate();
	identify(var);

	identify(*var);

	delete var;
	return (0);
}
