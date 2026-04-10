#ifndef _FORM_H
#define _FORM_H

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>

class Form
{
	private:
		const std::string m_name;
		bool m_is_signed;
		const int m_sign_grade;
		const int m_execute_grade;

	public:

class GradeTooHighException : std::runtime_error
	{
		private:
			std::string m_msg;
		public:
			GradeTooHighException(int grade);
			const char* what() const throw();
			~GradeTooHighException() throw();
	};
	
	class GradeTooLowException : std::runtime_error
	{
		private:
			std::string m_msg;
		public:
			GradeTooLowException(int grade);
			const char* what() const throw();
			~GradeTooLowException() throw();
	};

		Form();
		Form(std::string name, int sign_grade, int execute_grade) throw(Form::GradeTooHighException, Form::GradeTooLowException);
		Form(const Form &other);
		Form& operator=(const Form& other);
		~Form();
	
	

	// Form getters
	std::string getName();
	bool isSigned();
	int getSignGrade();
	int getExecuteGrade();

};

#endif
