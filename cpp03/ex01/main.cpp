#include "ScavTrap.hpp"

int main(void)
{
  ScavTrap Demeter("Demeter");
  ScavTrap Hera("Hera");
  ScavTrap tmp("tmp");
  ScavTrap Ares(tmp);

  Ares = Demeter;

  Demeter.attack("Hera");
  Hera.beRepaired(20);
  Ares.takeDamage(200);

  Demeter.guardGate();
}
