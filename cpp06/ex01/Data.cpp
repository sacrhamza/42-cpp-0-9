#include "Data.hpp"
#include <iostream>

Data::Data(void) : m_data("some important data") {}


Data::Data(const std::string data) : m_data(data){}

Data::Data(const Data& other) : m_data(other.m_data) {}

Data& Data::operator=(const Data& other) {
	m_data = other.m_data;
	return (*this);
}

const std::string& Data::getData(void) const{
	return (m_data);
}

Data::~Data(void) {}
