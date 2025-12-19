#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat : Animal
{
  private:
    Cat(void);
  public:
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat(void);
};

#endif
