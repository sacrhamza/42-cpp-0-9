#include "Cat.hpp"

Cat::Cat(void)
{
  type = "Cat";
  std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
  std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
  std::cout << "Cat copy assigment operator called\n";
  type = other.type;

  return (*this);
}

void Cat::makeSound(void) const
{
  std::cout << type << " meows\n";
}

Cat::~Cat(void)
{
  std::cout << "Cat destructor called\n";
}
