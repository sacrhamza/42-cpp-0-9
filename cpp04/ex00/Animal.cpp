#include "Animal.hpp"

Animal::Animal(void)
{
  std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
  std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
  std::cout << "Animal copy assigment operator called\n";

  type = other.type;

  return (*this);
}

void Animal::makeSound(void) const
{
  std::cout << "Animal makes sound\n";
}

std::string Animal::getType() const
{
  return (type);
}

Animal::~Animal(void)
{
  std::cout << "Animal destructor called\n";
}
