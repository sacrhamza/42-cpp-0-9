#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>

#include <stack>
#include <list>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <sstream>

class RPN {
	private:
		std::stack<int, std::list<int> > m_stack;
		int charToInt(char c);
		int add(int a, int b);
		int substract(int a, int b);
		int multiply(int a, int b);
		char getChar(const std::string& str, std::size_t& pos);
		int getInt(std::string& str, std::size_t& pos);

		int doSimpleMath(int a, int b, char op);
	public:
		RPN(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		int calculate(const std::string& str);
		~RPN(void);
};

#endif
