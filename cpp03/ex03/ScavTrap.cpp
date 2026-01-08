#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	m_energy_points = 50;
  std::cout << "ScavTrap Default Constructor: My heart is quiet because it belongs to " << m_name << "\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
  std::cout << "Parameterized Constructor: " << m_name << " born to fight!!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
  std::cout << "ScavTrap Copy Constructor: " << other.m_name << " born to fight!!\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
  std::cout << "ScavTrap Copy Assignment operator: I was " << m_name << " and now I am " << other.m_name << "\n";
  m_name = other.m_name;
  m_hit_points = other.m_hit_points;
  m_energy_points = other.m_energy_points;
  m_attack_damage = other.m_attack_damage;

  return (*this);
}

void ScavTrap::attack(const std::string &target)
{
  if (m_energy_points > 0 && m_hit_points > 0)
  {
    m_energy_points--;
    std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage\n";
  }
  else {
    std::cout << "ScavTrap "<< m_name << ": I can't attack, what has no function deserves no pursuit.";
  }
}

void ScavTrap::guardGate(void) const
{
  std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap(void)
{
  std::cout << "ScavTrap destroctor called\n";
}
