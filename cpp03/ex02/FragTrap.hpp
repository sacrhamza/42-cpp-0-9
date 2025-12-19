#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : private ClapTrap
{
	private:
		FragTrap(void);
	public:
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		FragTrap(const std::string &name);
		~FragTrap(void);
		void highFivesGuys(void);
};

#endif
