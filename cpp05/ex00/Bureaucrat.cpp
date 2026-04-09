#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	m_name("unkown"),
	m_grade(150)
{
  std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) :
	m_name(name)
{
  std::cout << "Bureaucrat paramatrized constructor called\n";
	if (grade > 150){
		throw (GradeTooLowException(grade));
	}
	else if (grade < 1) {
		throw (GradeTooHighException(grade));
	}
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


unsigned int Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
	if (m_grade == 1) {
		throw Bureaucrat::GradeTooHighException(m_grade);
	}
	return (--m_grade);
}

unsigned int Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
	if (m_grade == 150) {
		throw Bureaucrat::GradeTooLowException(m_grade);
	}
	return (++m_grade);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(unsigned int grade)
	: runtime_error("grade too high"),
		m_grade(grade)	
{
	std::stringstream stream;
	stream << m_grade;
	m_msg = runtime_error::what() + std::string(": ") + stream.str();
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (m_msg.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
	std::cout << "GradeTooLowException destructor\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(unsigned int grade)
	: runtime_error("grade too low"),
		m_grade(grade)	
{
	std::stringstream stream;
	stream << m_grade;
	m_msg = runtime_error::what() + std::string(": ") + stream.str();
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (m_msg.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	std::cout << "GradeTooHighException destructor\n";
}
