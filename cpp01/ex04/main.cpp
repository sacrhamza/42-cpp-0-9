#include <iostream>
#include <fstream>
#include "Str.hpp"

void close_in_out(std::ifstream &infile, std::ofstream &outfile)
{
  if (infile.is_open())
    infile.close();
  if (outfile.is_open())
    outfile.close();
}

int main(int argc, char **argv)
{
  std::string str;
  std::string filename;
  std::ifstream infile;
  std::ofstream outfile;

  if (argc == 4)
  {
    Str input(argv[2], argv[3]);
    infile.open(argv[1]);

    if (infile.fail())
      std::cerr << "error opening file for reading\n";
    else
    {
      filename = argv[1] + std::string(".replace");
      outfile.open(filename.c_str());

      if (outfile.fail())
        std::cerr << "error creating file for righting\n";
      while(std::getline(infile, str))
      {
        outfile <<  input.replace(str) << "\n";
      }
    }
    close_in_out(infile, outfile);
  }
  return (0);
}
