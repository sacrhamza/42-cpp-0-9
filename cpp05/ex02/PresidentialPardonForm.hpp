#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp" 

class PresidentialPardonForm : public AForm {
	private:
		std::string m_target;
	protected:
    PresidentialPardonForm(void);
		void takeAction() const;

  public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm(void);
};

#endif
