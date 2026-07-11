#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class Data {
	private:
		std::string m_data;
	public:
		Data(void);
		Data(const std::string data);
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data(void);
		const std::string& getData(void) const;
};

#endif
