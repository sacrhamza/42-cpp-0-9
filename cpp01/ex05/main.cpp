#include <iostream>
#include "Harl.hpp"

int main(void)
{
  Harl harl;

  harl.complain("debug");
  harl.complain("info");
  harl.complain("warning");
  harl.complain("error");
  void (Harl::*func)(std::string str) = &Harl::complain;
  (harl.*func)("hey");
  return (0);
}
