#include "Dog.hpp"
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal()
{
  m_brain = new Brain();
  type = "Dog";
  std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal()
{
  std::cout << "Dog copy constructor called\n";
  type = other.type;

  m_brain = new Brain();
  *m_brain = *other.m_brain;
}

Dog& Dog::operator=(const Dog& other)
{
  std::cout << "Dog copy assigment operator called\n";
  type = other.type;

  *m_brain = *other.m_brain;
  return (*this);
}


void Dog::makeSound(void) const
{
  std::cout << type << " barks\n";
}

Dog::~Dog(void)
{
  delete m_brain;
  std::cout << "Dog destructor called\n";
}
