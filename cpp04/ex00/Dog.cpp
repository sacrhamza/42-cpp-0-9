#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
  std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other)
{
  std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
  std::cout << "Dog copy assigment operator called\n";
  return (*this);
}

Dog::~Dog(void)
{
  std::cout << "Dog destroctor called\n";
}
