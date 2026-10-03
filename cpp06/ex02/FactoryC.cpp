#include "FactoryC.hpp"

FactoryC::FactoryC(void) : Factory() {}

FactoryC::FactoryC(const FactoryC& other) : Factory(other) {
}

FactoryC& FactoryC::operator=(const FactoryC& other) {
	Factory::operator=(other);
	return (*this);
}

Base* FactoryC::createNew() const{
	return (new C);
}

FactoryC::~FactoryC(void) {}
