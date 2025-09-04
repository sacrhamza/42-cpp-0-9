#include <ios>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
  char str[10];
  std::fstream file;

  if (argc == 4)
  {
    file.open(argv[1]);
    if (file.fail())
      std::cerr << "error opening file " << argv[1] << "\n";
    // std::fstream outfile;
    file.getline(str, 9);
    while(*str)
    {
      std::cout << str << "\n";
      file.getline(str, 9);
    }
  }
  return (0);
}
