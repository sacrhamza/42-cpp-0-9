#ifndef CHARHANDLER_HPP
#define CHARHANDLER_HPP
#include <iostream>
#include "Handler.hpp"

class CharHandler : public Handler {
  public:
    CharHandler(void);
    CharHandler(const CharHandler& other);
    CharHandler& operator=(const CharHandler& other);
		void handle(const std::string& str);
    ~CharHandler(void);
		void handler();
};

#endif
