#ifndef FLOATHANDLER_HPP
#define FLOATHANDLER_HPP

#include <iostream>
#include <sstream>
#include "Handler.hpp"

#include "utils.hpp"
#include "iomanip"
#include <cerrno>
#include <cstdlib>



class FloatHandler : public Handler {
  public:
    FloatHandler(void);
    FloatHandler(const FloatHandler& other);
    FloatHandler& operator=(const FloatHandler& other);
		void handle(const std::string& str);
    ~FloatHandler(void);
};

#endif
