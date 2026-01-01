#include "Str.hpp"

Str::Str(std::string from, std::string to) :
  _from(from),
  _to(to)
{
  _len = from.length();
};

std::string& Str::replace(std::string &str)
{
  size_t position;

  if (_from == "")
    return (str);
  position = 0;
  while ((position = str.find(_from, position)) != std::string::npos)
  {
    str.erase(position, _len).insert(position, _to);
    position += _to.length();
  }
  return (str);
}

void Str::set_from(std::string from){
  _from = from;
}

void Str::set_to(std::string to){
  _to = to;
}

const std::string& Str::get_from(void) const
{
  return _from;
}
const std::string& Str::get_to(void) const
{
  return _to;
};
