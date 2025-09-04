#include "Weapon.hpp"

std::string& Weapon::getType(void)
{
  return (m_type);
}

void Weapon::setType(std::string new_type_)
{
  m_type = new_type_;
}

Weapon::Weapon(std::string type_)
{
  m_type = type_;
}
