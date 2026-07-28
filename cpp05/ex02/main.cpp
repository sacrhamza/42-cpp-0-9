#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
	ShrubberyCreationForm shrub("shrub");
	Bureaucrat b("Bureaucrat", 1);
	b.signForm(shrub)	;
	shrub.execute(b);

	RobotomyRequestForm  robot("robot");
	Bureaucrat low("Bureaucrat", 150);
	try {
		low.signForm(robot);
		low.executeForm(robot);
	}
	catch (const std::exception& e) {

	}

	PresidentialPardonForm president("president");
	b.signForm(president);
	president.execute(b);

	return (0);
}
