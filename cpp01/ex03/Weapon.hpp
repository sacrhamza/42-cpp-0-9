#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
  private:
    std::string m_type;

  public:
    std::string& getType(void);
    void setType(std::string new_type_);
    Weapon(std::string type_);
};

#endif
