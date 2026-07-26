#include "Span.hpp"
#include <iostream>
#include <stdexcept>

Span::Span(void) {
  std::cout << "Span default constructor called\n";
}


Span::Span(unsigned int n) : m_max(n) {}

Span::Span(const Span& other) : 
	m_max(other.m_max),
m_elems(other.m_elems){}

Span& Span::operator=(const Span& other) {
	m_max = other.m_max;
	m_max = other.m_max;
  return (*this);
}

void Span::addNumber(int num) {
	if (m_elems.size() + 1 > m_max) {
		throw (std::out_of_range("max reached"));
	}
	m_elems.insert(num);
}


int Span::shortestSpan() const {
	if (m_elems.size() <= 1) {
		throw (std::runtime_error("error"));
	}
	std::set<int>::const_iterator i = m_elems.begin();
	std::set<int>::const_iterator next_iter = ++m_elems.begin();
	int next;
	int current;
	int short_span = (*next_iter) - (*i);

	for (; next_iter != m_elems.end(); ++i, ++next_iter) {
		next = *(next_iter);
		current = *i;
		if ((next - current) < short_span) {
			short_span = next - current;
		}
	}
	return (short_span);
}

// void Span::print() const{
// 	for (int a : m_elems) {
// 		std::cout << a << "\n";
// 	}
// }


int Span::longestSpan() const {
	if (m_elems.size() <= 1) {
		throw (std::runtime_error("the list of element <= 1"));
	}
	int min = *m_elems.begin();
	int max = *(++m_elems.rend());
	std::cout << "min = " << min << "\n";
	std::cout << "max = " << max << "\n";
	return (max - min);
}

Span::~Span(void) {}
