#ifndef HUMANA_HPP
# define HUMANA_HPP
  
#include "Weapon.hpp"
class HumanA
{
  public:
    Weapon &m_weapon;
    std::string m_name;

    HumanA(std::string name_, Weapon &weapon_);
    void attack(void);
};
#endif
