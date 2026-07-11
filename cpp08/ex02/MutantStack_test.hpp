#ifndef _MUTANTSTACK_H
#define _MUTANTSTACK_H

#include <deque>
#include <iostream>

template <typename value_type, class Container = std::deque<value_type> > class MutantStack {
	typedef value_type& ref;
	typedef const value_type& const_ref;
	typedef std::size_t size_type;
	private:
		Container m_data;
	public:

		class iterator {
			private:
				typename Container::iterator m_it;
			public:
			iterator(typename Container::iterator& it) : m_it(it) {}
			iterator(const iterator& it) : m_it(it.m_it) {}

			iterator& operator++(int) {
				m_it++;
				return (*this);
			}
			iterator operator++() {
				iterator tmp;
				tmp.m_it = m_it++;
				return (tmp);
			}
			iterator& operator--(int) {
				m_it--;
				return (*this);
			}
			iterator operator--() {
				iterator tmp;
				tmp.m_it = m_it--;
				return (tmp);
			}
			value_type& operator*(void) {
				return (*m_it);
			}
		};

		MutantStack(const Container& cont = Container()) : m_data(cont) {}
		MutantStack(const MutantStack& other) : m_data(other.m_data) {}

		ref top(void) {
			return (m_data.back());
		}
		const_ref top(void) const {
			return (m_data.back());
		}

		bool empty() const {
			return (m_data.empty());
		}

		size_type size() const {
			return (m_data.size());
		}
		
		void push(const value_type& value) 
		{
			m_data.push_back(value);
		};

		void pop() {
			m_data.pop_back();
		}


		iterator begin() {
			return (m_data.begin());
		}

		iterator end() {
			return (m_data.end());
		}
};

#endif
