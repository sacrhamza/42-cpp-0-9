#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		FragTrap(void);

	public:
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		FragTrap(const std::string &name);
		void highFivesGuys(void) const;
		~FragTrap(void);
};

#endif
