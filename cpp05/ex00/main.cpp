#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat normal_bureaucrat("hey", 1);	
	std::cout << normal_bureaucrat;

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
		normal_bureaucrat.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}
