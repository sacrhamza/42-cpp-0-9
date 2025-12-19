#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
  type = "WrongCat";
  std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
  std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
  std::cout << "WrongCat copy assigment operator called\n";
  type = other.type;

  return (*this);
}

void WrongCat::makeSound(void) const
{
  std::cout << type << " meows\n";
}

WrongCat::~WrongCat(void)
{
  std::cout << "WrongCat destroctor called\n";
}
