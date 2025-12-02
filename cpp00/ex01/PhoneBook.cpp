#include "PhoneBook.hpp"
#include <ios>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

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

  int i = 0;
  do {
    i++;
    std::cout << message << "\n";
    std::getline(std::cin >> std::ws, input);
    std::cout << "hey" << i;
  }while (input.empty() && !std::cin.eof());
  if (std::cin.eof())
  {
    std::cout << "\nby!!";
    exit(1);
  }
  return (input);
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
  int l_max;
  std::string first_name;
  std::string last_name;
  std::string nickname;

  l_max = (m_full) ? 8 : m_currentIndex;
  put_aligned_text("index");
  put_aligned_text("first_name");
  put_aligned_text("last_name");
  put_aligned_text("nickname");

  for (int index = 0; index < l_max; index++)
  {	
    std::cout << "\n";
    std::cout << std::setw(10) << index;
    std::cout << "|";
    put_aligned_text(m_contacts[index].get_first_name());
    put_aligned_text(m_contacts[index].get_last_name());
    put_aligned_text(m_contacts[index].get_nickname());
  }
  std::cout << "\n";
  int displayIndex;
  std::cout << "give me the display entry [just a number]: ";
  std::cin >> displayIndex;
  if (std::cin.fail())
    exit (1);
  if ((displayIndex > 7 || displayIndex < 0) || (displayIndex > m_currentIndex && !m_full))
    std::cout << "error: index is not in range\n";
  else
  {
    std::cout << "first_name: " << m_contacts[displayIndex].get_first_name() << "\n";
    std::cout << "last_name: " << m_contacts[displayIndex].get_last_name() << "\n";
    std::cout << "nickname: " << m_contacts[displayIndex].get_nickname() << "\n";
  };
}
