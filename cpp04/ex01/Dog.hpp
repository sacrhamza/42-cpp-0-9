#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain *m_brain;
  public:
    Dog(void);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    void makeSound(void) const;
    ~Dog(void);
};

#endif
