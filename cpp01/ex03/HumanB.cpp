#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name_)
{
  m_name = name_;
  m_weapon = NULL;
}

void HumanB::attack(void)
{
  std::cout << m_name << " attacks with their "; 
  if (m_weapon != NULL)
    std::cout << m_weapon->getType() << "\n";
}

void HumanB::setWeapon(Weapon& weapon_)
{
  m_weapon = &weapon_;
}
