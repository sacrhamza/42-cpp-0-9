#include "Intern.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
  return (*this);
}

AForm *Intern::makeForm(const std::string& name, const std::string& target) {
	typedef  AForm *(Intern::*HandlerFunc)(const std::string &target);
	struct AFormMap {
		std::string name;
		HandlerFunc func;
	};
	 HandlerFunc handler;

	AForm* form;

	AFormMap handlerMap[3] = {
		{"shrubbery creation", &Intern::newShrubberyCreationForm},
		{"robotomy request", &Intern::newRobotomyRequestForm},
		{"presidential pardon", &Intern::newPresidentialPardonForm}
	};

	int len = sizeof(handlerMap) / sizeof(AFormMap);
	for (int idx = 0; idx < len; idx++) {
		if (handlerMap[idx].name == name) {
			handler = handlerMap[idx].func;
			form = (this->*handler)(target);
			std::cout << "Intern creates " << name << "\n";
			return (form);
		}
	}
	std::cerr << "the form name does not exist: " << name << "\n";
	return (NULL);
}

AForm* Intern::newShrubberyCreationForm(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::newRobotomyRequestForm(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::newPresidentialPardonForm(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

Intern::~Intern(void) {}
