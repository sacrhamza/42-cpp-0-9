#ifndef _MUTANTSTACK_H
#define _MUTANTSTACK_H

#include <deque>
#include <iostream>
#include <stack>

template <typename value_type, class Container = std::deque<value_type> > class MutantStack : public std::stack<value_type, Container> {

	protected:

	typedef std::stack<value_type, Container> base_stack ;
	typedef typename base_stack::container_type container_type;
	typedef typename base_stack::reference reference;
	typedef typename base_stack::const_reference const_reference;
	typedef typename base_stack::size_type size_type;
	typedef typename container_type::iterator iterator_type;

	private:
		
		Container m_data;
	public:

		class iterator {
			protected:
				iterator_type m_it;
			public:	
			iterator(const iterator_type& it) : m_it(it) {}
			iterator(const iterator& it) : m_it(it.m_it) {}

			iterator& operator++(int) {
				m_it++;
				return (*this);
			}

			iterator operator++() {
				iterator tmp(m_it++);
				return (tmp);
			}

			iterator& operator--(int) {
				std::cout << "hey\n";
				m_it--;
				return (*this);
			}

			iterator operator--() {
				iterator tmp(m_it--);
				return (tmp);
			}

			value_type& operator*(void) {
				return (*m_it);
			}

			bool operator!=(const iterator& it) {
				return (m_it != it.m_it);
			}
		};

		MutantStack(const Container& cont = Container()) : base_stack(cont) {}
		MutantStack(const MutantStack& other) : base_stack(other) {}

		// reference top(void) {
		// 	return base_stack::top();
		// }
		//
		// const_reference top(void) const {
		// 	return base_stack::top();
		// }
		//
		// bool empty() const {
		// 	return base_stack::empty();
		// }
		//
		// size_type size() const {
		// 	return base_stack::size();
		// }
		
		// void push(const value_type& value) 
		// {
		// 	base_stack::push(value);
		// };

		// void pop() {
		// 	base_stack::pop();
		// }

		iterator begin() {
			return (base_stack::c.begin());
		}

		iterator end() {
			return (base_stack::c.end());
		}
};

#endif
