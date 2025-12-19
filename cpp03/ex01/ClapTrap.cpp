#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
  std::cout << "ClapTrap Default Constructor: My heart is quiet because it belongs to no one.”\n";
}

ClapTrap::ClapTrap(const std::string& name) :
  m_name(name),
  m_hit_points(10),
  m_energy_points(10),
  m_attack_damage(0)
{
  std::cout << "ClapTrap Constructor: " << m_name << " born to fight!!\n";
}


ClapTrap::ClapTrap(const ClapTrap& other) :
  m_name(other.m_name),
  m_hit_points(other.m_hit_points),
  m_energy_points(other.m_energy_points),
  m_attack_damage(other.m_attack_damage)
{
  std::cout << "ClapTrap Copy Constructor: " << other.m_name << " born to fight!!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
  std::cout << "ClapTrap Copy Assignment operator: I was " << m_name << " and now I am " << other.m_name << "\n";
  m_name = other.m_name;
  m_hit_points = other.m_hit_points;
  m_energy_points = other.m_energy_points;
  m_attack_damage = other.m_attack_damage;
  return (*this);
}

ClapTrap::~ClapTrap(void)
{
  std::cout << "ClapTrap Destructor: " << m_name << " death is not the end\n";
}

void ClapTrap::attack(const std::string &target)
{ 
  if (m_energy_points > 0 && m_hit_points > 0)
  {
    m_energy_points--;
    std::cout << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage\n";
  }
  else {
    std::cout << m_name << ": I can't attack, what has no function deserves no pursuit.";
  }
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (m_energy_points > 0 && m_hit_points > 0)
  {
    m_energy_points--;
    m_hit_points += amount;
    std::cout << m_name << " repairs itself and regains " << amount << " hit points, total: " << m_hit_points << " hit points\n";
  }
  else {
    std::cout << m_name << ": I can't repair myself, what has no function deserves no pursuit.\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (amount > m_hit_points)
    m_hit_points = 0;
  else
    m_hit_points -= amount;
  std::cout << m_name << " have been attacked, and now have " << m_hit_points << " hit points\n";
}
