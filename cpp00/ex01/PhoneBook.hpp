#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

class PhoneBook
{
  private:
    Contact m_contacts[8];
    int m_currentIndex;
    bool m_full;
    void put_aligned_text(std::string str);

  public:
    static std::string get_data(std::string message);
    void add_contact(void);
    void search_contacts();
    PhoneBook(void);
};

bool str_is_printable(std::string& str);

#endif
