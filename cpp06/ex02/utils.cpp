#include "utils.hpp"


Base* generate(void) {
	FactoryA facA;
	FactoryB facB;
	FactoryC facC;


	Factory* FactoryList[3] = {&facA, &facB, &facC};

	int val = std::rand();

	return (FactoryList[val % 3]->createNew());
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "it is A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "it is B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "it is C" << std::endl;
	}
	else {
		std::cout << "unknown" << std::endl;
	}
}

void identify(Base& p) {
	Base b;
	try {

		b = dynamic_cast<A&>(p)	;
		std::cout << "it is A" << std::endl;

	} 
	catch (const std::exception& e) {

		try {
			b = dynamic_cast<B&>(p)	;
			std::cout << "it is B" << std::endl;
		}
		catch (const std::exception&) {

			try {
				b = dynamic_cast<C&>(p)	;
				std::cout << "it is C" << std::endl;
			} 
			catch (const std::exception& e) {
				std::cout << "unknown" << std::endl;
			}

		}	

	}
}
