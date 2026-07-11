#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>

class Form;

class Bureaucrat
{
	protected:
		Bureaucrat(void);

	private:
		const std::string m_name;
		unsigned int m_grade;

	public:
		class GradeTooHighException : public std::runtime_error
		{
			private:
				std::string m_msg;
			public:
				GradeTooHighException(unsigned int grade, const std::string& msg = "");
				const char* what() const throw();
				~GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::runtime_error
		{
			private:
				std::string m_msg;

			public:	
				GradeTooLowException(unsigned int grade, const std::string&msg = "");
				const char* what() const throw();
				~GradeTooLowException() throw();
		};

		Bureaucrat(const std::string &name, unsigned int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName(void) const;
		unsigned int getGrade(void) const;

		Bureaucrat& incrementGrade() throw(Bureaucrat::GradeTooHighException);
		Bureaucrat& decrementGrade() throw(Bureaucrat::GradeTooLowException);


		void signForm(Form& form) const;

		~Bureaucrat(void);

};

// insertion operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
