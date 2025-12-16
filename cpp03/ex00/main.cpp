#include "ClapTrap.hpp"

int main(void)
{
  std::string zeus_name = "zeus";
  std::string hades_name = "hades_name";

  ClapTrap Zeus("zeus");
  ClapTrap Hades("hades");


  Zeus.beRepaired(20);
  Hades.attack(zeus_name);
  Zeus.takeDamage(20);
  Hades.beRepaired(5);
  Zeus.takeDamage(25);

  Zeus.attack(zeus_name);
}
