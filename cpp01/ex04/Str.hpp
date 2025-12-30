#ifndef STR_H
#define STR_H
#include <string>

class Str
{
  private:
    size_t _len;
    std::string _from;
    std::string _to;
  public:
    Str(std::string from, std::string to);
    std::string& replace(std::string &str);
    void set_from(std::string from);
    void set_to(std::string to);
    const std::string &get_from(void) const;
    const std::string &get_to(void) const;
};

#endif
