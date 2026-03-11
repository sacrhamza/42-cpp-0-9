#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
    // std::string m_name;
    DiamondTrap(void);

  public:
    DiamondTrap(const DiamondTrap& other);
		DiamondTrap(const std::string &name);
    DiamondTrap& operator=(const DiamondTrap& other);
		void whoAmI();
    ~DiamondTrap(void);
		void print();
};

#endif
