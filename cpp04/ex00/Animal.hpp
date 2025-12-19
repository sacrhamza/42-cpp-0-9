#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal(void);
		void makeSound(void);
};

#endif
