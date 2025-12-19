#include "ClapTrap.hpp"

int main(void)
{
  std::string zeus_name = "zeus";
  std::string hades_name = "hades";
  std::string name = "methology";

  ClapTrap Zeus(zeus_name);
  ClapTrap Hades(hades_name);
  ClapTrap Empty("empty");

  ClapTrap Aphrodite(Empty);

  Empty = Zeus;

  Zeus.beRepaired(20);
  Hades.attack(zeus_name);
  Zeus.takeDamage(20);
  Hades.beRepaired(5);
  Zeus.takeDamage(25);

  Zeus.attack(zeus_name);
}
