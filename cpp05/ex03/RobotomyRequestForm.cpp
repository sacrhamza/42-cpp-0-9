#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45),
m_target(target){}

void RobotomyRequestForm::takeAction() const{
	bool success = std::rand() % 2;

	if (success) {
		std::cout << m_target << " has been robotomized.\n";
	} else {
		std::cout << "the robotomy failed.\n";
	}
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other),
	m_target(other.m_target){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	m_target = other.m_target;
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
