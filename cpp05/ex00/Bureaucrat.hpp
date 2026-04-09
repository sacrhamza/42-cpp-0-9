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
		unsigned int m_grade;

	public:
		class GradeTooHighException : public std::runtime_error
		{
			private:
				unsigned int m_grade;
				std::string m_msg;
			public:
				GradeTooHighException(unsigned int grade);
				const char* what() const throw();
				~GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::runtime_error
		{
			private:
				unsigned int m_grade;
				std::string m_msg;

			public:	
				GradeTooLowException(unsigned int grade);
				const char* what() const throw();
				~GradeTooLowException() throw();
		};

		Bureaucrat(const std::string &name, unsigned int grade = 150) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName(void) const;
		int getGrade(void) const;

		unsigned int incrementGrade() throw(Bureaucrat::GradeTooHighException);
		unsigned int decrementGrade() throw(Bureaucrat::GradeTooLowException);

		~Bureaucrat(void);

};

// insertion operator
std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
