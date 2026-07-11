#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{

  // Animal animal; // variable type is abstract class

  Dog dog;
  Cat cat;

  Dog new_dog = dog;
  Cat new_cat(cat);
  return 0;
}
