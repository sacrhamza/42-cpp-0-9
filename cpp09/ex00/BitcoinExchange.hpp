#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <functional>
#include <iostream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float, std::greater<std::string> > m_map;
  public:
		static void checkValue(float &num, const std::string& value);
		static void checkDate(const std::string& date);
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
		void exchange(const std::string& file_name);
    ~BitcoinExchange(void);
};

#endif
