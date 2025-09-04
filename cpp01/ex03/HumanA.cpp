#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name_, Weapon& weapon_) : m_weapon(weapon_)
{
  m_name = name_;
}

void HumanA::attack(void)
{
  std::cout << m_name << " attacks with their " << m_weapon.getType() << "\n";
}
