#include <iostream>
#include <fstream>
#include <istream>
#include "Str.hpp"

int main(int argc, char **argv)
{
  std::string str;
  std::string filename;
  std::fstream file;
  std::fstream replaced;

  if (argc == 4)
  {
    Str input(argv[2], argv[3]);
    file.open(argv[1]);
    filename = argv[1] + std::string(".replace");
    std::cout << filename << "\n";
    // std::string to_replace(argv[2]);
    if (file.fail())
      std::cerr << "error opening file " << argv[1] << "\n";
    while(std::getline(file, str))
    {
      std::cout << "[" << input.replace(str)  << "]" << str.length() << "\n";
    }
    file.close();
  }
  return (0);
}
