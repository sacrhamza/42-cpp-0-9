#include "Animal.hpp"

Animal::Animal(void)
{
  type = "Animal";
  std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other)
{
  std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
  std::cout << "Animal copy assigment operator called\n";
  return (*this);
}

void Animal::makeSound(void)
{
  std::cout << "";
}

Animal::~Animal(void)
{
  std::cout << "Animal destroctor called\n";
}
