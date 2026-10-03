#ifndef FACTORY_B_HPP
#define FACTORY_B_HPP

#include <iostream>
#include "Factory.hpp"
#include "B.hpp"

class FactoryB : public Factory{
	public:
		FactoryB(void);
		FactoryB(const FactoryB& other);
		FactoryB& operator=(const FactoryB& other);

		virtual Base* createNew() const ;

		~FactoryB(void);
};

#endif
