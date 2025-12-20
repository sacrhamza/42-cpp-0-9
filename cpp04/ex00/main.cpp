#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();

  // cleanup
  delete meta;
  delete j;
  delete i;
 

  const WrongAnimal* wrong_meta = new WrongAnimal();
  const WrongAnimal* wrong_j = new WrongCat();

  const WrongAnimal tmp = *wrong_meta;
  tmp.makeSound();

  std::cout << wrong_meta->getType() << " " << std::endl;
  std::cout << wrong_j->getType() << " " << std::endl;
  wrong_meta->makeSound(); //will output the cat sound!
  wrong_j->makeSound();

  // cleanup
  delete wrong_meta;
  delete wrong_j;
  return 0;
}
