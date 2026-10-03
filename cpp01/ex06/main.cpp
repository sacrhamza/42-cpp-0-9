#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
  Harl harl;
  if (argc == 2)
  {
    harl.filter(argv[1]);
  }
  return (0);
}
