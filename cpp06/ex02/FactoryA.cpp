#include "FactoryA.hpp"
#include <iostream>

FactoryA::FactoryA(void) : Factory() {}

FactoryA::FactoryA(const FactoryA& other) : Factory(other) {
}

FactoryA& FactoryA::operator=(const FactoryA& other) {
	Factory::operator=(other);
  return (*this);
}

		Base* FactoryA::createNew() const{
			return (new A);
		}

FactoryA::~FactoryA(void) {}
