#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook phonebook;
  std::string choice;
  
  while (true)
  {
    PhoneBook::get_data(choice, "COMMAND (ADD | SEARCH | EXIT): ");
    if (choice == "ADD")
      phonebook.add_contact();
    else if (choice == "SEARCH")
      phonebook.search_contacts();
    else if (choice == "EXIT")
      break ;
  }

  return (0);
}
