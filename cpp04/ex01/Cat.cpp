#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
  m_brain = new Brain();
  type = "Cat";
  std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
  std::cout << "Cat copy constructor called\n";

  m_brain = new Brain();

  *m_brain = *other.m_brain;
}

Cat& Cat::operator=(const Cat& other)
{
  std::cout << "Cat copy assigment operator called\n";
  type = other.type;


  *m_brain = *other.m_brain;
  return (*this);
}

void Cat::makeSound(void) const
{
  std::cout << type << " meows\n";
}

Cat::~Cat(void)
{
  delete m_brain;
  std::cout << "Cat destructor called\n";
}
