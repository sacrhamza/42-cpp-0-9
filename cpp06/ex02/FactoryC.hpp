#ifndef FACTORY_C_HPP
#define FACTORY_C_HPP

#include <iostream>
#include "Factory.hpp"
#include "C.hpp"

class FactoryC : public Factory{
  public:
    FactoryC(void);
    FactoryC(const FactoryC& other);
    FactoryC& operator=(const FactoryC& other);

		virtual Base* createNew() const ;

    ~FactoryC(void);
};

#endif
