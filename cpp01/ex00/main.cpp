#include "Zombie.hpp"
#include <algorithm>

int main(void)
{
  // test announce
  Zombie first_zombie("soldier");
  first_zombie.announce();

  std::cout << "\n===========\n\n";

  // test newZombie
  Zombie *zombie_ptr = newZombie("Fighter");
  zombie_ptr->announce();
  delete zombie_ptr;

  std::cout << "\n===========\n\n";

  randomChump("horseman");
  return (0);
}
