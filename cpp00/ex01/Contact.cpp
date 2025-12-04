#include "Contact.hpp"

void Contact::set_first_name(std::string firstName)
{
  m_firstName = firstName;
}

void Contact::set_last_name(std::string lastName)
{
  m_lastName = lastName;
}

void Contact::set_phone_number(std::string phoneNumber)
{
  m_phonNUmber = phoneNumber;
}

void Contact::set_darkest_secret(std::string darkestSecret)
{
  m_darkestSecret = darkestSecret;
}


void Contact::set_nickname(std::string nickName)
{
  m_nickName = nickName;
}

const std::string Contact::get_first_name(void)
{
  return (m_firstName);
}

const std::string Contact::get_last_name(void)
{
  return (m_firstName);
}

const std::string Contact::get_phone_number(void)
{
  return (m_phonNUmber);
}

const std::string Contact::get_darkest_secret(void)
{
  return (m_darkestSecret);
}


const std::string Contact::get_nickname(void)
{
  return (m_nickName);
}
