#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :
  m_name(name),
  m_hit_points(10),
  m_energy_points(10),
  m_attack_damage(0)
{
  std::cout << m_name << " born to fight!!\n";
}

ClapTrap::~ClapTrap(void)
{
  std::cout << m_name << " death is not the end\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
  *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
  m_name = other.m_name;
  m_hit_points = other.m_hit_points;
  m_energy_points = other.m_energy_points;
  m_attack_damage = other.m_attack_damage;
  return (*this);
}

void ClapTrap::attack(const std::string &target)
{ 
  if (m_energy_points > 0 && m_hit_points > 0)
  {
    m_energy_points--;
    m_hit_points--;
    std::cout << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (m_energy_points > 0 && m_hit_points > 0)
  {
    m_energy_points--;
    m_hit_points += amount;
    std::cout << m_name << " repairs itself and regains " << amount << " hit points!\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount)
{
  m_attack_damage += amount;
  std::cout << m_name << " have been attacked and lose " << amount << "damage\n";
}

