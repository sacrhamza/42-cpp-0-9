#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : Animal
{
  private:
    Dog(void);
  public:
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog(void);
};

#endif
