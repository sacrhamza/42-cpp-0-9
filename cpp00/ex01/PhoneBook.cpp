#include "PhoneBook.hpp"
#include <ios>
#include <iostream>

#include <iomanip>

PhoneBook::PhoneBook(void)
{
  m_currentIndex = 0;
  m_full = false;
}


void PhoneBook::print(void)
{
  int l_max;

  l_max = (m_full) ? 3 : m_currentIndex;
    std::cout << "\n================\n";
  for (int i = 0; i < l_max; i++)
  {
    std::cout << "contacts[" << i << "] = ";
    std::cout << "m_firstName = " << m_contacts[i].m_firstName << "\n";
    std::cout << "m_lastName = " << m_contacts[i].m_lastName << "\n";
    std::cout << "m_firstName = " << m_contacts[i].m_phonNUmber << "\n";
    std::cout << "m_firstName = " << m_contacts[i].m_darkestSecret << "\n";
  }
    std::cout << "\n================\n";
}

void PhoneBook::save_contact(Contact& new_contact)
{
  if (m_currentIndex == 3)
  {
    m_full = true;
    m_currentIndex = 0; 
  }

  m_contacts[m_currentIndex] = new_contact;

  m_currentIndex++;
}

void PhoneBook::add_contact(void)
{
  Contact l_contact;

  get_data(l_contact.m_firstName, "enter your first name: ");
  get_data(l_contact.m_lastName, "enter your last name: ");
  get_data(l_contact.m_nickName, "enter your nick name: ");
  get_data(l_contact.m_darkestSecret, "enter your darkest secret: ");
  get_data(l_contact.m_phonNUmber, "enter your phone number: ");
  save_contact(l_contact);
}

void PhoneBook::get_data(std::string& r_field, std::string message)
{
   do {
      std::cout << message;
      std::getline(std::cin, r_field);
    }while (r_field.empty());
}

void PhoneBook::search_contacts()
{
  int l_max;

  l_max = (m_full) ? 3 : m_currentIndex;
 
    std::cout << std::setw(10) << std::right;
    std::cout << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::setw(10) << "first_name";
    std::cout << "|";
    std::cout << std::setw(10) << "last_name";

  for (int i = 0; i < l_max; i++)
  {
    std::cout << "\n";
    std::cout << std::setw(10) << i;
    std::cout << "|";
    std::cout << std::setfill('.') << std::setw(10) << m_contacts[i].m_firstName;
    std::cout << "|";
    std::cout<< std::setw(10) << m_contacts[i].m_lastName;
  }
  std::cout << "\n";
  // }
}
