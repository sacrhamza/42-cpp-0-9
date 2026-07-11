#ifndef _FORM_H
#define _FORM_H

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>

class Bureaucrat;

class Form
{
	private:
		const std::string m_name;
		bool m_is_signed;
		const unsigned int m_sign_grade;
		const unsigned int m_execute_grade;

	protected:
		Form();

	public:

	class GradeTooHighException : public std::runtime_error
	{
		private:
			std::string m_msg;
		public:
			GradeTooHighException(unsigned int grade);
			const char* what() const throw();
			~GradeTooHighException() throw();
	};
	
	class GradeTooLowException : public std::runtime_error
	{
		private:
			std::string m_msg;
		public:
			GradeTooLowException(unsigned int grade);
			const char* what() const throw();
			~GradeTooLowException() throw();
	};

		Form(std::string name, unsigned int sign_grade, unsigned int execute_grade) throw(Form::GradeTooHighException, Form::GradeTooLowException);
		Form(const Form &other);
		Form& operator=(const Form& other);
		void beSigned(const Bureaucrat& bureaucrat) throw(Form::GradeTooLowException);
		~Form();
	
	

	// Form getters
	std::string getName() const;
	bool isSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExecuteGrade() const;

};

std::ostream& operator<<(std::ostream& out, const Form& form);


#endif




