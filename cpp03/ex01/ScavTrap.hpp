#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : private ClapTrap
{
	private:
		ScavTrap(void);
	public:
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		ScavTrap(const std::string &name);
		~ScavTrap(void);
		void guardGate(void);
};

#endif
