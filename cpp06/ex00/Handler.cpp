#include "Handler.hpp"
#include <iostream>

Handler::Handler(void) : m_nextHandler(NULL) {
}

Handler::Handler(const Handler& other) : m_nextHandler(other.m_nextHandler) {
}

Handler& Handler::operator=(const Handler& other) {
	m_nextHandler = other.m_nextHandler;
  return (*this);
}


void Handler::setNextHandler(Handler* nextHandler) {
	m_nextHandler = nextHandler;
}

Handler::~Handler(void) {
}

