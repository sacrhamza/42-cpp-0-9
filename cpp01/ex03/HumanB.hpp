#ifndef HUMANB_HPP
# define HUMANB_HPP
  
#include "Weapon.hpp"
class HumanB
{
  private:
    Weapon* m_weapon;
    std::string m_name;
  public:
    HumanB(std::string name);
    void attack(void);
    void setWeapon(Weapon &weapon);
};
#endif
