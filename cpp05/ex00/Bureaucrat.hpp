#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>


class Bureaucrat
{
	protected:
		Bureaucrat(void);

	private:
		const std::string m_name;
		int m_grade;

	public:
		class GradeTooHighException : public std::runtime_error
		{
			private:
				std::string m_msg;
			public:
				GradeTooHighException(int grade);
				const char* what() const throw();
				~GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::runtime_error
		{
			private:
				std::string m_msg;

			public:	
				GradeTooLowException(int grade);
				const char* what() const throw();
				~GradeTooLowException() throw();
		};

		Bureaucrat(const std::string &name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName(void) const;
		int getGrade(void) const;

		int incrementGrade() throw(Bureaucrat::GradeTooHighException);
		int decrementGrade() throw(Bureaucrat::GradeTooLowException);

		~Bureaucrat(void);

};

// insertion operator
std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
