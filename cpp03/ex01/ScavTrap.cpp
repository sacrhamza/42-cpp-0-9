#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
  std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
  std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
  std::cout << "ScavTrap copy assigment operator called\n";
  return (*this);
}

ScavTrap::~ScavTrap(void)
{
  std::cout << "ScavTrap destroctor called\n";
}
