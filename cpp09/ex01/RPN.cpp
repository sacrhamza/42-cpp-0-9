#include "RPN.hpp"
#include <cctype>
#include <stdexcept>

RPN::RPN(void) {}

RPN::RPN(const RPN& other) :
	m_stack(other.m_stack){}

RPN& RPN::operator=(const RPN& other) {
	m_stack = other.m_stack;
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
			if (b == 0)
				throw (std::runtime_error("division by 0"));
			return (a / b);
	}
	return (0);
}


char RPN::getChar(const std::string& str, std::size_t& pos) {
	while (pos < str.length() && str.at(pos) == ' ') {
		pos++;
	}
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

		if (std::isdigit(c)) {
			if (i < str.length() && std::isdigit(str[i+1])) {
				std::string err = "num: " + str.substr(i, 2) + " > 9";
				throw (std::runtime_error(err));
			}
			m_stack.push(charToInt(c));
		}
		else if (isOperator(c)){
			if (m_stack.size() < 2)
				throw (std::runtime_error("too few numbers in stack"));
			int b = m_stack.top(); m_stack.pop();
			int a = m_stack.top(); m_stack.pop();

			m_stack.push(doSimpleMath(a, b, c));
		}
		else {
			throw (std::runtime_error("error unknown: " + str.substr(i, 1)));
		}
		++i;
		while (i < str.length() && str[i] == ' ') {
			++i;
		}
	}
	if (m_stack.size() != 1)
		throw (std::runtime_error("stack size != 1"));
	return (m_stack.top());
}

RPN::~RPN(void) {}
