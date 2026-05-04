#include <exception>
#include<iostream>
#include "Array.hpp"

int main(void){
	// test constructor
	Array<int> ar(20);

	// test subscript operator
	ar[0] = 20;
	std::cout << ar[0] << "\n";

	Array<std::string> ar2(2);
	ar2[0] = "hello";
	ar2[1] = "hello";

	// default constructor
	Array<std::string> ar3;
	ar3 = ar2;

	// size member function
	std::cout << "the size of array ar3 is " << ar3.size() << "\n";

	Array<std::string> ar4(ar3);
	ar3[0] = "hi";
	ar3[1] = "hi";

	ar3.print("ar3");
	ar4.print("ar4");

	// test const size function
	const Array<std::string> const_arr(ar3);
	std::cout << const_arr.size() << "\n";

	try {
		// 200: out of range
		ar[200] = 200;
	}
	catch(const std::exception& e) {
		std::cout << "out of range";
	}

	return (0);
}
