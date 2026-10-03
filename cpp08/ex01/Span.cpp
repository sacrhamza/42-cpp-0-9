#include "Span.hpp"
#include <algorithm>
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
	if (&other != this) {
		m_max = other.m_max;
		m_elems = other.m_elems;
	}
  return (*this);
}

void Span::addNumber(int num) {
	if (m_elems.size() == m_max) {
		throw (std::out_of_range("max reached"));
	}
	m_elems.push_back(num);
}


int Span::shortestSpan() {
	if (m_elems.size() <= 1) {
		throw (std::runtime_error("the list of element <= 1"));
	}
	std::sort(m_elems.begin(), m_elems.end());

	ContConstIter iter = m_elems.begin();
	ContConstIter next_iter = iter + 1;

	int next;
	int current;
	int result;
	int short_span = (*next_iter) - (*iter);

	for (; next_iter != m_elems.end(); ++next_iter) {
		next = *(next_iter);
		current = *iter;
		result = (next - current);
		if (result < short_span) {
			short_span = result;
		}
		iter = next_iter;
	}
	return (short_span);
}

int Span::longestSpan() {
	if (m_elems.size() <= 1) {
		throw (std::runtime_error("the list of element <= 1"));
	}
	int min = *std::min_element(m_elems.begin(), m_elems.end());
	int max = *std::max_element(m_elems.begin(), m_elems.end());

	return (max - min);
}

Span::~Span(void) {}
