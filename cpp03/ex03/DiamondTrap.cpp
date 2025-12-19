#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{
  std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
  std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
  std::cout << "DiamondTrap copy assigment operator called\n";
  return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
  std::cout << "DiamondTrap destroctor called\n";
}
