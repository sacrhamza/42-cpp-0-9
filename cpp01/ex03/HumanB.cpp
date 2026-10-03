#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
  m_name = name;
  m_weapon = NULL;
}

void HumanB::attack(void)
{
  std::cout << m_name << " attacks with their "; 

  if (m_weapon != NULL)
    std::cout << m_weapon->getType() << "\n";
  else
    std::cout << "(no weapon type)";

}

void HumanB::setWeapon(Weapon& weapon)
{
  m_weapon = &weapon;
}
