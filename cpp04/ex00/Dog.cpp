#include "Dog.hpp"
#include <iostream>
#include "Animal.hpp"

Dog::Dog(void)
{
  type = "Dog";
  std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other)
{
  std::cout << "Dog copy constructor called\n";
  type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
  std::cout << "Dog copy assigment operator called\n";
  type = other.type;

  return (*this);
}


void Dog::makeSound(void) const
{
  std::cout << type << " barks\n";
}

Dog::~Dog(void)
{
  std::cout << "Dog destroctor called\n";
}
