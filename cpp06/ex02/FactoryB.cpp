#include "FactoryB.hpp"

FactoryB::FactoryB(void) : Factory() {}

FactoryB::FactoryB(const FactoryB& other) : Factory(other) {
}

FactoryB& FactoryB::operator=(const FactoryB& other) {
	Factory::operator=(other);
	return (*this);
}

Base* FactoryB::createNew() const{
	return (new B);
}

FactoryB::~FactoryB(void) {}
