#include<iostream>
#include"RPN.hpp"

int main(int argc, char **argv){
	if (argc != 2) {
		std::cerr << "usage: ./RPN 'operation' \n";
		return (1);
	}
	RPN rpn;
	try {
		std::cout << rpn.calculate(argv[1]) << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
		return (1);
	}
	return (0);
}
