#ifndef FACTORY_HPP
#define FACTORY_HPP
#include <iostream>
#include "Base.hpp"

class Factory {
  protected:
    Factory(void);
    Factory(const Factory& other);
    Factory& operator=(const Factory& other);
    virtual ~Factory(void);
	public:
		virtual Base* createNew() const = 0;
};

#endif
