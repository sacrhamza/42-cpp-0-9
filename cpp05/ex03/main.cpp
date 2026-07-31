#include<iostream>
#include "Bureaucrat.hpp"
#include"Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void){
	Intern intern;
	Bureaucrat b("Bureaucrat", 1);

	AForm *form = intern.makeForm("robotomy request", "home");
	delete form;

	try {

	form = intern.makeForm("shrubbery creation", "home");
	b.signForm(*form);
	form->execute(b);
	delete form;

	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}


	form = intern.makeForm("presidential pardon", "home");
	delete form;

	return (0);
}
