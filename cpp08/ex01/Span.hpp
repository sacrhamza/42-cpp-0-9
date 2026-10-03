#ifndef SPAN_HPP
#define SPAN_HPP

#include <csetjmp>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>


class Span {
	private:
		typedef std::vector<int>::iterator ContIter;
		typedef std::vector<int>::const_iterator ContConstIter;
		unsigned int m_max;
		std::vector<int> m_elems;
		Span(void);

	public:

		template<typename InputIter> void addRange(InputIter first, InputIter last) {
			std::size_t size = std::distance(first, last);
			if (m_max < size + m_elems.size()) {
					throw (std::out_of_range("out of range"));
			}
			m_elems.insert(m_elems.end(), first, last);
		}

		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		~Span(void);
};

#endif
