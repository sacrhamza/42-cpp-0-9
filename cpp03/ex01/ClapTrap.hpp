#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  private:
    std::string m_name;
    unsigned int m_hit_points;
    unsigned int m_energy_points;
    unsigned int m_attack_damage;

    ClapTrap(void);

  public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);

    void attack(const std::string &target);
    void beRepaired(unsigned int amount);
    void takeDamage(unsigned int amount);
    
    ~ClapTrap(void);
};

#endif
