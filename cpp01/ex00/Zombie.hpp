#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
  private:
    std::string _name;

  public:
    Zombie(std::string name);
    void announce(void);
    ~Zombie(void);
};


void randomChump(std::string name);

Zombie* newZombie(std::string name);

#endif
