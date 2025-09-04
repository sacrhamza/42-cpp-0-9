#ifndef HUMANB_HPP
# define HUMANB_HPP
  
#include "Weapon.hpp"
class HumanB
{
  public:
    Weapon* m_weapon;
    std::string m_name;

    HumanB(std::string name_);
    void attack(void);
    void setWeapon(Weapon &weapon_);
};
#endif
