#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
  std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other)
{
  std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
  std::cout << "Cat copy assigment operator called\n";
  return (*this);
}

Cat::~Cat(void)
{
  std::cout << "Cat destroctor called\n";
}
