#ifndef FACTORY_A_HPP
#define FACTORY_A_HPP
#include <iostream>
#include "Factory.hpp"
#include "A.hpp"

class FactoryA : public Factory{
  public:
    FactoryA(void);
    FactoryA(const FactoryA& other);
    FactoryA& operator=(const FactoryA& other);

		virtual Base* createNew() const ;

    ~FactoryA(void);
};

#endif
