#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
	protected:
		ScavTrap(void);

	public:
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		ScavTrap(const std::string &name);
		~ScavTrap(void);
		void guardGate(void) const;
    void attack(const std::string &target);
};

#endif
