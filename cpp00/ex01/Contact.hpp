#ifndef CONTACT_HPP
#define  CONTACT_HPP

#include <string>

class Contact
{
  private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_phonNUmber;
    std::string m_nickName;
    std::string m_darkestSecret;
  public:
    void set_first_name(std::string firstName);
    void set_last_name(std::string lastName);
    void set_nickname(std::string lastName);
    void set_phone_number(std::string phoneNumber);
    void set_darkest_secret(std::string darkestSecret);
    std::string get_first_name(void);
    std::string get_last_name(void);
    std::string get_phone_number(void);
    std::string get_darkest_secret(void);
    std::string get_nickname(void);
};
#endif
