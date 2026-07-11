#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : 
	m_name("default"),
	m_is_signed(false),
	m_sign_grade(150),
	m_execute_grade(150)
 {
	std::cout << "Default Constructor called\n";
}

AForm::AForm(std::string name, unsigned int sign_grade, unsigned int execute_grade) throw(AForm::GradeTooHighException, AForm::GradeTooLowException) :
	m_name(name), 
	m_sign_grade(sign_grade),
	m_execute_grade(execute_grade)
	{
		if (sign_grade > 150 || execute_grade > 150) {
			if (sign_grade > 150)
				throw (AForm::GradeTooLowException(sign_grade));
			throw (AForm::GradeTooLowException(execute_grade));
		}
		else if (sign_grade < 1 || execute_grade < 1) {
			if (sign_grade < 1)
				throw (AForm::GradeTooHighException(sign_grade));
			throw (AForm::GradeTooHighException(execute_grade));
		}
		m_is_signed = false;
}

AForm::AForm(const AForm &other) :
	m_name(other.m_name),
	m_is_signed(other.m_is_signed),
	m_sign_grade(other.m_sign_grade),
	m_execute_grade(other.m_execute_grade)
{
}

AForm& AForm::operator=(const AForm& other)
{
	m_is_signed = other.m_is_signed;
	return (*this);
}


std::ostream& operator<<(std::ostream& out, const AForm& form) {
	std::string isSigned = form.isSigned() ? " is signed" : " is not signed";

	out << "form " << "'" << form.getName() << "'," << isSigned << " sign grade = "
		<< form.getSignGrade() << " execute grade = " << form.getExecuteGrade()
		<< "\n";

	return (out);
}


void AForm::beSigned(const Bureaucrat& bureaucrat) throw(AForm::GradeTooLowException)
{
	unsigned int grade = bureaucrat.getGrade();
	if (grade > m_sign_grade)	
	{
		throw AForm::GradeTooLowException(grade);
	}
	m_is_signed = true;
}

AForm::~AForm(void) {
	std::cout << "AForm Destructor called\n";
}

std::string AForm::getName(void) const {
	return (m_name);
}

bool AForm::isSigned(void) const {
	return (m_is_signed);
}

unsigned int AForm::getSignGrade(void) const {
	return (m_sign_grade);
};

unsigned int AForm::getExecuteGrade(void) const {
	return (m_execute_grade);
};

AForm::GradeTooHighException::GradeTooHighException(unsigned int grade)
: runtime_error("AForm grade too high") {
	std::stringstream stream;
	stream << grade;

	m_msg = runtime_error::what() + std::string(": ") + stream.str();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return (m_msg.c_str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {

}

AForm::GradeTooLowException::GradeTooLowException(unsigned int grade)
: runtime_error("AForm grade too low") {
	std::stringstream stream;
	stream << grade;

	m_msg = runtime_error::what() + std::string(": ") + stream.str();	
}

const char* AForm::GradeTooLowException::what() const throw() {
	return (m_msg.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

