#include <iostream>

void print_arg(std::string str)
{
  for (size_t index = 0; index < str.size(); index++)
  {
    std::cout << char(std::toupper(str.at(index)));
  }
}

void print_args(char **args, int max)
{
    for (int index = 0; index < max; index++)
    {
      print_arg(args[index]);
    }
}

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    print_args(argv + 1, argc - 1);
  }
  else 
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  return (0);
}
