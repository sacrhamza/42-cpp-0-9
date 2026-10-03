#ifndef _UTILS_H
#define _UTILS_H

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "FactoryA.hpp"
#include "FactoryB.hpp"
#include "FactoryC.hpp"

#include <cstdlib>
#include <exception>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
