#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{
	try{
		Bureaucrat normal_bureaucrat("hey", 1);	
		std::cout << normal_bureaucrat;
		normal_bureaucrat.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat c("some name", 200);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat c("some name", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat d("some name", 150);
		d.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}
