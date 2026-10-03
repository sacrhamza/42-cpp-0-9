#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
  type = "WrongAnimal";
  std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
  std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
  std::cout << "WrongAnimal copy assigment operator called\n";
  type = other.type;

  return (*this);
}

void WrongAnimal::makeSound(void) const
{
  std::cout << type << " makes sound\n";
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

WrongAnimal::~WrongAnimal(void)
{
  std::cout << "WrongAnimal destructor called\n";
}
