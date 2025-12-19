#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap string constructor called\n";
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_damage = 20;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	m_name = other.m_name;
	m_hit_points = other.m_hit_points;
	m_energy_points = other.m_energy_points;
	m_attack_damage = other.m_attack_damage;

	std::cout << "FragTrap copy assigment operator called\n";
	return (*this);
}


void FragTrap::highFivesGuys(void)
{
	std::cout << m_name << ": great job all the fighters around the world, see you in Elysian Fields\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destroctor called\n";
}
