#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	m_name("unkown"),
	m_grade(150)
{
  std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	m_name(name)
{
  std::cout << "Bureaucrat paramatrized constructor called\n";
	if (grade > 150)
		;
	else if (grade < 1)
		;
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	m_name(other.m_name),
	m_grade(other.m_grade)	
{
  std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
  std::cout << "Bureaucrat copy assigment operator called\n";

	m_grade = other.m_grade;

  return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (m_name);
}

int Bureaucrat::getGrade(void) const
{
	return (m_grade);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (out);
}

Bureaucrat::~Bureaucrat(void)
{
  std::cout << "Bureaucrat destroctor called\n";
}


int Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
	if (m_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	return (--m_grade);
}

int Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
	if (m_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	return (++m_grade);
}

void Bureaucrat::GradeTooHighException::hey()
{
	std::cout << "hey";
}
