#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) :
	m_name("unkown"),
	m_grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException) :
	m_name(name)
{
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
	m_grade(other.m_grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	m_grade = other.m_grade;

	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (m_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (m_grade);
}


void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << "\n";
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << m_name << " couldn't sign " << form
			<< " because " << e.what() << "\n";
	}
}


void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << m_name << " executed " << form.getName() << "\n";
	}
	catch (const std::runtime_error& e) {
		std::cout << "can't excute the form because: " << e.what() << "\n";
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (out);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destroctor called\n";
}

Bureaucrat&  Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
	if (m_grade == 1) {
		throw Bureaucrat::GradeTooHighException(m_grade, "can't increment grade");
	}
	--m_grade;
	return (*this);
}

Bureaucrat& Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
	if (m_grade == 150) {
		throw Bureaucrat::GradeTooLowException(m_grade, "can't decrement grade");
	}
	++m_grade;
	return (*this);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(unsigned int grade, const std::string& msg)
	: runtime_error("grade too high")
{
	std::stringstream stream;
	stream << grade;
	m_msg = runtime_error::what() + std::string(": ") + stream.str() + (!msg.empty() ? ", " + msg : "");
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (m_msg.c_str());
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
	std::cout << "GradeTooLowException destructor\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(unsigned int grade, const std::string& msg)
	: runtime_error("Bureaucrat grade too low")	
{
	std::stringstream stream;
	stream << grade;
	m_msg = runtime_error::what() + std::string(": ") + stream.str() + (!msg.empty() ? ", " + msg : "");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (m_msg.c_str());
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	std::cout << "GradeTooHighException destructor\n";
}
