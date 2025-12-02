#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
  _name = name;
}

void Zombie::announce(void)
{
  std::cout << _name << ": >: BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(void)
{
  std::cout << _name << ": dead twice!!\n";
}
