#include "Factory.hpp"
#include <iostream>

Factory::Factory(void) {}

Factory::Factory(const Factory& other) {
	(void)other;
}

Factory& Factory::operator=(const Factory& other) {
	(void)other;
  return (*this);
}

Factory::~Factory(void) {}
