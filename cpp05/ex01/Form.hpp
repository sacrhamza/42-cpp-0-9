#ifndef _FORM_H
#define _FORM_H

#include <stdexcept>
#include <string>

class Form
{
	private:
		const std::string m_name;
		bool m_is_signed;
		const int m_sign_grade;
		const int m_execute_grade;

	public:
		Form() throw();
		Form(std::string name, int sign_grade, int execute_grade) throw();
		class GradeTooHighException : std::runtime_error
	{
		public:
			GradeTooHighException() throw();
			const char* what() throw();
	};
		class GradeTooLowException : std::runtime_error
	{
		public:
			GradeTooLowException() throw();
			const char* what() throw();
	};
	std::string getName();
	bool isSigned();
	int getSignGrade();
	int getExecuteGrade();

};

#endif
