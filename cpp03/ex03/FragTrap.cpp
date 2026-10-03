#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	m_hit_points = 100;
	m_attack_damage = 30;
  std::cout << "FragTrap Default Constructor: My heart is quiet because it belongs to " << m_name << "\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
  std::cout << "FragTrap Constructor: " << m_name << " born to fight!!\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
  std::cout << "FragTrap Copy Constructor: " << other.m_name << " born to fight!!\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
  std::cout << "FragTrap Copy Assignment operator: I was " << m_name << " and now I am " << other.m_name << "\n";
	m_name = other.m_name;
	m_hit_points = other.m_hit_points;
	m_energy_points = other.m_energy_points;
	m_attack_damage = other.m_attack_damage;

	return (*this);
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << m_name << ": great job all the fighters around the world, see you in Elysian Fields\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destroctor called\n";
}
