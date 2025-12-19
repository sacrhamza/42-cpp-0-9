#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap(void);

	public:
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		FragTrap(const std::string &name);
		void highFivesGuys(void);
		~FragTrap(void);
};

#endif
