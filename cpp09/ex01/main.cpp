#include<iostream>
#include"RPN.hpp"

int main(void){
	RPN rpn;
	try {
	std::cout << rpn.calculate("3 4 + 5 6 + *") << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}
	return (0);
}
