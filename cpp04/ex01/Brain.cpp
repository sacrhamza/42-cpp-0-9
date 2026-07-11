#include "Brain.hpp"

Brain::Brain(void)
{
  std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other)
{
  for (int i = 0; i < 100; i++)
    ideas[i] = other.ideas[i];

  std::cout << "Brain copy constructor called\n";
}

Brain& Brain::operator=(const Brain& other)
{
  for (int i = 0; i < 100; i++)
    ideas[i] = other.ideas[i];

  std::cout << "Brain copy assigment operator called\n";

  return (*this);
}

Brain::~Brain(void)
{
  std::cout << "Brain destroctor called\n";
}
