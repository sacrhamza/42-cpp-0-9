#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap trap("something");
	trap.print();

	std::cout << "==============\n";

	DiamondTrap albert("Albert");
	albert = trap;
	albert.print();

	std::cout << "==============\n";

	DiamondTrap someone(albert);
	someone.print();

	someone.attack("albert");
	someone.whoAmI();

	someone.highFivesGuys();

	someone.guardGate();
}
