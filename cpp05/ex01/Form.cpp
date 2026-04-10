#include "Form.hpp"

Form::Form(void) : 
	m_name("default"),
	m_is_signed(false),
	m_sign_grade(150),
	m_execute_grade(150)
 {
	
}

Form::Form(std::string name, int sign_grade, int execute_grade) throw(Form::GradeTooHighException, Form::GradeTooLowException) :
	m_name(name), 
	m_sign_grade(sign_grade),
	m_execute_grade(execute_grade)
	{
		if (sign_grade > 150 || execute_grade > 150) {
			if (sign_grade > 150)
				throw (Form::GradeTooLowException(sign_grade));
			throw (Form::GradeTooLowException(execute_grade));
		}
		else if (sign_grade < 1 || execute_grade < 1) {
			if (sign_grade < 1)
				throw (Form::GradeTooHighException(sign_grade));
			throw (Form::GradeTooHighException(execute_grade));
		}
		m_is_signed = false;
}

Form::Form(const Form &other) :
	m_name(other.m_name),
	m_execute_grade(other.m_execute_grade),
	m_sign_grade(other.m_sign_grade),
	m_is_signed(other.m_is_signed)
{
	std::cout << "Copy Constructor called\n";
}

Form& Form::operator=(const Form& other)
{
	m_is_signed = other.m_is_signed;
	return (*this);
}

Form::~Form(void) {
	std::cout << "Form Destructor called\n";
}

std::string Form::getName(void) {
	return (m_name);
}

bool Form::isSigned(void) {
	return (m_is_signed);
}

int Form::getSignGrade(void) {
	return (m_sign_grade);
};

int Form::getExecuteGrade(void) {
	return (m_execute_grade);
};

Form::GradeTooHighException::GradeTooHighException(int grade)
: runtime_error("Form grade too high") {
	std::stringstream stream;
	stream << grade;

	m_msg = runtime_error::what() + std::string(": ") + stream.str();
}

const char* Form::GradeTooHighException::what() const throw() {
	return (m_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(int grade)
: runtime_error("Form grade too low") {
	std::stringstream stream;
	stream << grade;

	m_msg = runtime_error::what() + std::string(": ") + stream.str();	
}

const char* Form::GradeTooLowException::what() const throw() {
	return (m_msg.c_str());
}
