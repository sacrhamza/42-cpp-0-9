#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45) {
	bool success = ;

	if (success) {
		std::cout << target << " has been robotomized.\n";
	} else {
		std::cout << "the robotomy failed.\n";
	}
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
