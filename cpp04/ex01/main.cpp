#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
  Animal *animals[] = {new Dog(), new Dog(), new Cat(), new Cat};

  Dog tmp;
  Dog dog = tmp;


  for (size_t i = 0; i < sizeof(animals) / sizeof(Animal *); i++)
    delete animals[i];

  return 0;
}
