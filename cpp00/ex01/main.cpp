#include <iostream>
#include <stdio.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook phonebook;
  std::string choice;
  
  while (true)
  {
    choice = PhoneBook::get_data("COMMAND (ADD | SEARCH | EXIT): ");
    if (choice == "ADD")
      phonebook.add_contact();
    else if (choice == "SEARCH")
      phonebook.search_contacts();
    else if (choice == "EXIT")
      break ;
  }
  return (0);
}
