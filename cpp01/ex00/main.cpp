#include "Zombie.hpp"

int main(void)
{
  Zombie first_zombie("soldier");
  first_zombie.announce();

  std::cout << "\n===========\n\n";

  Zombie *zombie_ptr = newZombie("Fighter");
  zombie_ptr->announce();
  delete zombie_ptr;

  std::cout << "\n===========\n\n";

  randomChump("horseman");
  return (0);
}
