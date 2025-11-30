#include "PhoneBook.hpp"
#include <ios>
#include <iostream>
#include <iomanip>
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

	do {
		std::cout << message;
		std::getline(std::cin, input);
	}while (input.empty() && !std::cin.eof());
	if (std::cin.eof())
	{
		std::cout << "\nby!!";
		exit(1);
	}
	return (input);
}

void PhoneBook::search_contacts()
{
	int l_max;
	std::string first_name;
	std::string last_name;
	std::string nickname;

	l_max = (m_full) ? 8 : m_currentIndex;
  std::cout << "|     index|first_name| last_name|  nickname|";

	for (int index = 0; index < l_max; index++)
	{
		first_name = m_contacts[index].get_first_name();
		last_name = m_contacts[index].get_last_name();
		nickname =  m_contacts[index].get_nickname();

    first_name = (first_name.length() > 10) ? first_name.replace(9, first_name.length(), ".") : first_name.substr(0, 10);
    last_name = (last_name.length() > 10) ? last_name.replace(9, last_name.length(), ".") : last_name.substr(0, 10);
    nickname = (nickname.length() > 10) ? nickname.replace(9, nickname.length(), ".") : nickname.substr(0, 10);

		std::cout << "\n|";
		std::cout << std::setw(10) << index;
		std::cout << "|";
		std::cout << std::setw(10) << first_name;
		std::cout << "|";
		std::cout<< std::setw(10) << last_name;
		std::cout << "|";
		std::cout<< std::setw(10) << nickname;
		std::cout << "|";
	}
	std::cout << "\n";
}
