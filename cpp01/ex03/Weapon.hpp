#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
  private:
    std::string m_type;

  public:
    const std::string &getType(void);
    void setType(std::string new_type);
    Weapon(std::string type);
};

#endif
