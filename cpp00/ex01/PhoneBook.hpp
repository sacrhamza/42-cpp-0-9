#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
    Contact m_contacts[8];
    int m_currentIndex;
    bool m_full;
  public:
    static std::string get_data(std::string message);
    void add_contact(void);
    void search_contacts();
    PhoneBook(void);
};
#endif
