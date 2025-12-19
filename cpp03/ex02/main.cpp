#include "FragTrap.hpp"

int main(void)
{
  FragTrap Demeter("Demeter");
  FragTrap Hera("Hera");
  FragTrap tmp("tmp");
  FragTrap Ares(tmp);

  Ares = Demeter;

  Demeter.attack("Hera");
  Hera.beRepaired(20);
  Ares.takeDamage(200);

  Demeter.highFivesGuys();
}
