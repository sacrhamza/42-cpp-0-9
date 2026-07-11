#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook phonebook;
  std::string choice;
  
  while (!std::cin.fail())
  {
    choice = PhoneBook::get_data("COMMAND (ADD | SEARCH | EXIT): ");
    if (choice == "ADD")
      phonebook.add_contact();
    else if (choice == "SEARCH")
      phonebook.search_contacts();
    else if (choice == "EXIT")
      break ;
  }
  std::cout << "\nby!!";
  return (0);
}
