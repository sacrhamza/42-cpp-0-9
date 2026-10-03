#include <iostream>
#include <fstream>
#include "StringReplace.hpp"

void close_in_out(std::ifstream &infile, std::ofstream &outfile)
{
  if (infile.is_open())
    infile.close();
  if (outfile.is_open())
    outfile.close();
}

void replace_and_put(std::ifstream &infile, std::ofstream &outfile, StringReplace &replacer)
{
  std::string str;

  while(std::getline(infile, str))
  {
    outfile <<  replacer.replace(str);

    if (!infile.eof())
      outfile << "\n";
  }
}

int main(int argc, char **argv)
{
  std::string filename;
  std::ifstream infile;
  std::ofstream outfile;

  if (argc == 4)
  {
    StringReplace replacer(argv[2], argv[3]);

    infile.open(argv[1]);

    if (infile.fail())
      std::cerr << "error opening file for reading\n";
    else
    {
      filename = argv[1] + std::string(".replace");
      outfile.open(filename.c_str());

      if (outfile.fail())
        std::cerr << "error creating file for righting\n";

      replace_and_put(infile, outfile, replacer);
    }
    close_in_out(infile, outfile);
  }
  else {
    std::cerr << "num of arguments is not valid\n";
    return (1);
  }
  return (0);
}
