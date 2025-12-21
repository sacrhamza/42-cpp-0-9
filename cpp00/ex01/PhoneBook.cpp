#include "PhoneBook.hpp"
#include <cctype>
#include <stdlib.h>

PhoneBook::PhoneBook(void)
{
  m_currentIndex = 0;
  m_full = false;
}

void PhoneBook::add_contact(void)
{
  if (m_currentIndex == 8)
  {
    m_full = true;
    m_currentIndex = 0; 
  }

  m_contacts[m_currentIndex].set_first_name(get_data("enter your first name: "));
  m_contacts[m_currentIndex].set_last_name(get_data("enter your last name: "));
  m_contacts[m_currentIndex].set_nickname(get_data("enter your nick name: "));
  m_contacts[m_currentIndex].set_darkest_secret(get_data("enter your darkest secret: "));
  m_contacts[m_currentIndex].set_phone_number(get_data("enter your phone number: "));

  m_currentIndex++;
}

std::string PhoneBook::get_data(std::string message)
{
  std::string input;

  while (!std::cin.fail())
  {
    std::cout << message;
    std::getline(std::cin, input);
    if (!str_is_printable(input))
      continue ;
    if (!input.empty())
      return (input);
  };

  return ("");
}

void PhoneBook::put_aligned_text(std::string str)
{
  if (str.length() > 10)
    std::cout << str.replace(9, str.length(), ".");
  else
    std::cout << std::setw(10) << str.substr(0, 10);
  std::cout << "|";
}

void PhoneBook::search_contacts()
{
  int max;
  int displayIndex;

  max = (m_full) ? 8 : m_currentIndex;
  put_aligned_text("index");
  put_aligned_text("first_name");
  put_aligned_text("last_name");
  put_aligned_text("nickname");

  for (int index = 0; index < max; index++)
  {	
    std::cout << "\n";
    std::cout << std::setw(10) << index;
    std::cout << "|";
    put_aligned_text(m_contacts[index].get_first_name());
    put_aligned_text(m_contacts[index].get_last_name());
    put_aligned_text(m_contacts[index].get_nickname());
  }
  std::cout << "\n";

  std::cout << "give me the display entry [just a number]: ";
  std::cin >> displayIndex;

  if (std::cin.fail())
    return ;

  std::cin.ignore();
  if ((displayIndex > 7 || displayIndex < 0) || (displayIndex > m_currentIndex - 1 && !m_full))
    std::cout << "error: index is not in range\n";
  else
  {
    std::cout << "first_name: " << m_contacts[displayIndex].get_first_name() << "\n";
    std::cout << "last_name: " << m_contacts[displayIndex].get_last_name() << "\n";
    std::cout << "nickname: " << m_contacts[displayIndex].get_nickname() << "\n";
  };
}

bool str_is_printable(std::string& str)
{
  for (std::size_t index = 0; index < str.length(); index++)
  {
    if (!std::isprint(str.at(index)))
      return (false);
  }
  return (true);
}
