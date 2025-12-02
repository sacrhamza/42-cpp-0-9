#include "Zombie.hpp"

int main(void)
{
  int N = 5;
  std::string name = "something";

  Zombie *zombies = zombieHorde(N, name);

  if (zombies == NULL)
    return (1);

  for (int i = 0; i < N; ++i)
    zombies[i].announce();

  delete[] zombies;
  return (0);
}
