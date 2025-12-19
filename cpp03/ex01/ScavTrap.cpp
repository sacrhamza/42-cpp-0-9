#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called\n";
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	m_name = other.m_name;
	m_hit_points = other.m_hit_points;
	m_energy_points = other.m_energy_points;
	m_attack_damage = other.m_attack_damage;

	std::cout << "ScavTrap copy assigment operator called\n";
	return (*this);
}


void ScavTrap::guardGate(void)
{
	std::cout << m_name << " is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destroctor called\n";
}
