#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap(),
	ScavTrap(),
	FragTrap()
{
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap(),
	m_name(name)
{
	std::cout << "DiamondTrap  Parameterized Constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	m_name(other.m_name)
{
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	m_name = other.m_name;
	ClapTrap::m_name = other.ClapTrap::m_name;

	m_hit_points = other.m_hit_points;
	m_energy_points = other.m_energy_points;
	m_attack_damage = other.m_attack_damage;

	std::cout << "DiamondTrap copy assigment operator called\n";

	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destroctor called\n";
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "name = " << m_name << "\n";
	std::cout << "ClapTrap name = " << ClapTrap::m_name << "\n";
}

void DiamondTrap::print()
{
	whoAmI();
	std::cout << "hit points = " << m_hit_points << "\n";
	std::cout << "energy points = " << m_energy_points << "\n";
	std::cout << "attack damage = " << m_attack_damage << "\n";
}
