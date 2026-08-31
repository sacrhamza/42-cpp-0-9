#include <exception>
#include<iostream>
#include"./BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2) {
		return (1);
	}
	try {
		BitcoinExchange hey;
		hey.exchange(argv[1]);
	}
	catch (const std::exception& e) {
		std::cout << "database error: " << e.what() << "\n";
		return (1);
	}
	return (0);
}
