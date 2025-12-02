#include "Weapon.hpp"
#include <iostream>

int main(void)
{
  Weapon weapon("hey");

  std::string &name = weapon.getType();

  name = "jey";
  std::cout << "name = " << name << "get_name = " << weapon.getType();
  return (0);
}
