#include <iostream>
#include <fstream>
#include <string>

class Str
{
  private:
    size_t _len;
    std::string _from;
    std::string _to;
  public:
    Str(std::string from, std::string to) : _from(from),
    _to(to),
    _len(from.length()){};
    std::string& replace(std::string &str)
    {
      size_t position;
      while ((position = str.find(_from)) != std::string::npos)
      {
        str.erase(position, _len).insert(position, _to);
      }
      return (str);
    }
    void set_from(std::string from){
      _from = from;
    }
    void set_to(std::string to){
      _to = to;
    }
    const std::string &get_from(void) const {return _from;};
    const std::string &get_to(void) const {return _to;};
};

int main(int argc, char **argv)
{
  std::string str;
  std::fstream file;

  if (argc == 4)
  {
    file.open(argv[1]);
    Str input(argv[2], argv[3]);
    std::string to_replace(argv[2]);
    if (file.fail())
      std::cerr << "error opening file " << argv[1] << "\n";
    std::getline(file, str);
    while(!str.empty())
    {
      std::cout << input.replace(str) << "\n";
      std::getline(file, str);
    }
  }
  return (0);
}
