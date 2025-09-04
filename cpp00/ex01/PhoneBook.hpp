#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
#include <iostream>

class Contact
{
  public:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_phonNUmber;
    std::string m_nickName;
    std::string m_darkestSecret;
  // public:
  //   void set_first_name(std::string firstName);
  //   void set_last_name(std::string lastName);
  //   void set_phone_number(std::string phoneNumber);
  //   void set_darkest_secret(std::string darkestSecret);
};

class PhoneBook
{
  private:
    Contact m_contacts[3];
    int m_currentIndex;
    bool m_full;
    void save_contact(Contact& new_contact);
  public:
    static void get_data(std::string& r_field, std::string message);
    void add_contact(void);
    void search_contacts();
    void print(void);
    PhoneBook(void);
};
#endif
