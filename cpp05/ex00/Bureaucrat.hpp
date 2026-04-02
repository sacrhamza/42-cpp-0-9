#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class Bureaucrat
{
	protected:
		Bureaucrat(void);

	private:
		const std::string m_name;
		unsigned int m_grade;

	public:
		class GradeTooHighException : std::exception
		{
			void hey();
		};
		class GradeTooLowException : std::exception
		{
			// const char* what() const throw();
		};

		Bureaucrat(const std::string &name = "default", int grade = 150);
		// Bureaucrat(const std::string &name, int grade);
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
