#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <set>

class Span {
	private:
		unsigned int m_max;
		std::multiset<int> m_elems;
    Span(void);
  public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;
		void print() const;
    ~Span(void);
};

#endif
