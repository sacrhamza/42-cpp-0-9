#ifndef DOUBLEHANDLER_HPP
#define DOUBLEHANDLER_HPP

#include "Handler.hpp"
#include "utils.hpp"
#include <cerrno>
#include <iomanip>
#include <cstdlib>

class DoubleHandler : public Handler {
  public:
    DoubleHandler(void);
    DoubleHandler(const DoubleHandler& other);
    DoubleHandler& operator=(const DoubleHandler& other);
		void handle(const std::string& str);
    ~DoubleHandler(void);
};

#endif
