#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    typedef void (Harl::*handler_func_t)(void);

    struct s_handler{
      handler_func_t handler;
      std::string str;
    };

  public:
    void complain(std::string level);
};



#endif
