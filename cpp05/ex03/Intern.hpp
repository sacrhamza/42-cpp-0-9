#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "../ex02/AForm.hpp"
#include "../ex02/RobotomyRequestForm.hpp"
#include "../ex02/PresidentialPardonForm.hpp"
#include "../ex02/ShrubberyCreationForm.hpp"

class Intern {
  public:
    Intern(void);
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& name, const std::string& target);
		AForm* newShrubberyCreationForm(const std::string& target);
		AForm* newRobotomyRequestForm(const std::string& target);
		AForm* newPresidentialPardonForm(const std::string& target);

    ~Intern(void);
};

#endif
