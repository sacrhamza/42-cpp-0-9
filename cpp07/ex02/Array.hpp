#ifndef _ARRAY_H
#define _ARRAY_H

#include <exception>
#include <iostream>

template<typename T> class Array {
	private:

		T* m_elems;
		unsigned int m_size;

		void hard_copy(const Array& other) {
			m_size = other.m_size;	
			m_elems = new T[m_size];
			for (unsigned int i = 0; i < m_size; i++) {
				m_elems[i] = other.m_elems[i];
			}
		}

	public:

		Array(void) :
			m_elems(NULL),
			m_size(0){}

		Array(unsigned int n) {
			m_elems = new T[n];
			m_size = n;
		}

		Array(const Array& other) {
			hard_copy(other);
		}

		Array& operator=(const Array& other) {
			delete[] m_elems; 
			hard_copy(other);
			return (*this);
		}

		T& operator[](unsigned int n) throw(std::exception) {
			if (n >= m_size)
			{
				throw std::exception();
			}
			return (m_elems[n]);
		}

		unsigned int size(void) const {
			return (m_size);
		}

		void print(const std::string& name) const {
			for (unsigned int idx = 0; idx < m_size; idx++) {
				std::cout << name << "[" << idx << "] = " << m_elems[idx] << "\n";
			}
		}

		~Array() {
			delete[] m_elems;
		}


};

#endif
