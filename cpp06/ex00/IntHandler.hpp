#ifndef INTHANDLER_HPP
#define INTHANDLER_HPP
#include <iostream>
#include <sstream>
#include "Handler.hpp"

class IntHandler : public Handler {
  public:
    IntHandler(void);
    IntHandler(const IntHandler& other);
    IntHandler& operator=(const IntHandler& other);
		void handle(const std::string& str);
    ~IntHandler(void);
};

#endif
