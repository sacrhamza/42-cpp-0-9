#include "RPN.hpp"
#include <cctype>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

RPN::RPN(void) {
	std::cout << "RPN default constructor called\n";
}

RPN::RPN(const RPN& other) {
	std::cout << "RPN copy constructor called\n";
}

RPN& RPN::operator=(const RPN& other) {
	std::cout << "RPN copy assigment operator called\n";
	return (*this);
}

int RPN::add(int a, int b) {
	return (a + b);
}

int RPN::substract(int a, int b) {
	return (a - b);
}


int RPN::multiply(int a, int b) {
	return (a * b);
}

int RPN::charToInt(char c) {
	return (c - 48);
}

int RPN::getInt(std::string& str, std::size_t& pos) {
	int num = getChar(str, pos);
	if (!std::isdigit(num)) {
		throw (std::runtime_error("error"));
	}
	return (charToInt(num));
}

int RPN::doSimpleMath(int a, int b, char op) {
	switch (op) {
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
	}
	return (0);
}


char RPN::getChar(const std::string& str, std::size_t& pos) {
	while (pos < str.length() && str.at(pos) == ' ') {
		std::cout << "space\n";
		pos++;
	}
	//check here
	return (str[pos]);
}
bool isOperator(char c) {
	return (c == '-' || c == '+'
			|| c == '/' || c == '*');
}

int RPN::calculate(const std::string& str) {
	std::size_t i = 0;
	while (i < str.length()) {
		char c = getChar(str, i);
		++i;
		if (std::isdigit(c)) {
			m_stack.push(charToInt(c));
		}
		else if (isOperator(c)){
			if (m_stack.size() < 2)
				throw (std::runtime_error("too few numbers in stack"));
			int b = m_stack.top(); m_stack.pop();
			int a = m_stack.top(); m_stack.pop();
			std::cout << "a = " << a << "\n";
			std::cout << "b = " << b << "\n";
			m_stack.push(doSimpleMath(a, b, c));
		}
		else {
			throw (std::runtime_error("error"));
		}
		// std::cout << "hey " << i << "\n";
		// doSimpleMath(str, i);
		while (i < str.length() && std::isspace(str[i])) {
			++i;
		}
	}
	return (m_stack.top());
}

RPN::~RPN(void) {
	std::cout << "RPN destroctor called\n";
}
