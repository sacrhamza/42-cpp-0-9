#include <iostream>
#include "Harl.hpp"

int main(void)
{
  Harl harl;

  harl.complain("DEBUG");
  harl.complain("INFO");
  harl.complain("WARNING");
  harl.complain("ERROR");

  void (Harl::*func)(std::string str) = &Harl::complain;
  (harl.*func)("hey");

  return (0);
}
