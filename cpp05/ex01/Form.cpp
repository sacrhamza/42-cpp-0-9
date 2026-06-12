#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : 
	m_name("default"),
	m_is_signed(false),
	m_sign_grade(150),
	m_execute_grade(150)
 {
	std::cout << "Default Constructor called\n";
}

Form::Form(std::string name, unsigned int sign_grade, unsigned int execute_grade) throw(Form::GradeTooHighException, Form::GradeTooLowException) :
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
	m_is_signed(other.m_is_signed),
	m_sign_grade(other.m_sign_grade),
	m_execute_grade(other.m_execute_grade)
{
}

Form& Form::operator=(const Form& other)
{
	m_is_signed = other.m_is_signed;
	return (*this);
}


std::ostream& operator<<(std::ostream& out, const Form& form) {
	std::string isSigned = form.isSigned() ? " is signed" : " is not signed";

	out << "form " << "'" << form.getName() << "'," << isSigned << " sign grade = "
		<< form.getSignGrade() << " execute grade = " << form.getExecuteGrade()
		<< "\n";

	return (out);
}


void Form::beSigned(const Bureaucrat& bureaucrat) throw(Form::GradeTooLowException)
{
	unsigned int grade = bureaucrat.getGrade();
	if (grade > m_sign_grade)	
	{
		throw Form::GradeTooLowException(grade);
	}
	m_is_signed = true;
}

Form::~Form(void) {
	std::cout << "Form Destructor called\n";
}

std::string Form::getName(void) const {
	return (m_name);
}

bool Form::isSigned(void) const {
	return (m_is_signed);
}

unsigned int Form::getSignGrade(void) const {
	return (m_sign_grade);
};

unsigned int Form::getExecuteGrade(void) const {
	return (m_execute_grade);
};

Form::GradeTooHighException::GradeTooHighException(unsigned int grade)
: runtime_error("Form grade too high") {
	std::stringstream stream;
	stream << grade;

	m_msg = runtime_error::what() + std::string(": ") + stream.str();
}

const char* Form::GradeTooHighException::what() const throw() {
	return (m_msg.c_str());
}

Form::GradeTooHighException::~GradeTooHighException() throw() {

}

Form::GradeTooLowException::GradeTooLowException(unsigned int grade)
: runtime_error("Form grade too low") {
	std::stringstream stream;
	stream << grade;

	m_msg = runtime_error::what() + std::string(": ") + stream.str();	
}

const char* Form::GradeTooLowException::what() const throw() {
	return (m_msg.c_str());
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

