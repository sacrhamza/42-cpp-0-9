#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat
{
	protected:
		Bureaucrat(void);
	private:
		const std::string m_name;
		unsigned int m_grade;

	public:
		// Bureaucrat(void);
		//
		Bureaucrat(const std::string &name = "default", int grade = 150);
		// Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);
		const std::string getName(void) const;
		const int& getGrade(void) const;

	class GradeTooHighException;
	class GradeTooLowException;
};

std::ofstream &operator<<(std::ofstream &out, Bureaucrat bureaucrat);

class Bureaucrat::GradeTooHighException
{
	int hey(void);
	GradeTooLowException();
};

#endif
