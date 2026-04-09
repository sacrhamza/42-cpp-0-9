#include "Form.hpp"


Form::Form(std::string name, int sign_grade, int execute_grade) throw()
: m_name(name){
		
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

Form::GradeTooHighException::GradeTooHighException()
: runtime_error(""){

}
