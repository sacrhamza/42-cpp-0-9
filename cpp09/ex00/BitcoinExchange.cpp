#include "BitcoinExchange.hpp"
#include <cctype>
#include <cerrno>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <climits>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {}


std::string split(const std::string& str, char c, std::size_t& pos) {
	std::size_t char_pos = str.find(c, pos);

	// if (char_pos == std::string::npos) {
	// 	throw (std::runtime_error("not valid format"));
	// }

	// std::cout << "pos = " <<pos << "\n";
	// std::cout << "char pos = " <<char_pos << "\n";
	std::string res(str, pos, char_pos - pos);// = str.substr(pos, char_pos - pos); // 20,,20 pos = 3 char_pos = 4

	pos = char_pos + 1;

	return (res);
}

BitcoinExchange::BitcoinExchange(const std::string& data) {
	std::stringstream ss(data);
	std::string line;
	std::string err;
	float num;
	std::string date;
	std::size_t pos;
	while (std::getline(ss, line).good()) {
		pos = 0;
		try {
			date = split(line, ',', pos);
			std::string value(line, pos);
			checkDate(date);
			checkValue(num, value, err);
			// std::cout << "value = " << value << "\n";
			m_map[date] = num;
		}
		catch (const std::exception& e) {
			std::cout  << e.what() << ": " << line <<  "\n";
		}
		line = "";
	}
}

void BitcoinExchange::exchange(const std::string& file_name) {
	std::ifstream file(file_name.c_str());
	if (!file.is_open()) {
		throw (std::runtime_error("cant open file: " + file_name));
	}

	std::string line;
	std::string err;
	float num;
	std::string date;
	std::size_t pos;
	std::map<std::string, float>::const_iterator it;
	while (std::getline(file, line).good()) {
		pos = 0;
		try {
			date = split(line, ' ', pos);
			// std::cout << "date = " << date << "\n";
			std::string value_break = split(line, ' ', pos);
			// std::cout << "line break = \"" << value_break << "\"\n";
			std::string value(line, pos);
			// std::cout << "value = \"" << value << "\"\n";

			checkDate(date);
			checkValue(num, value, err);
			// std::cout << "value = " << value << "\n";
			it = m_map.find(date);
			if (it == m_map.end()) {
				it = m_map.lower_bound(date);
				// std::cout << "searching for lower bound\n";
				if (it == m_map.end()) {
					std::cout << "errror there is no value lower than that value " << value << "\n";
					it = m_map.upper_bound(date);
					// exit (1);
				}
			}
			std::cout << (it->second * num) << "\n";
			// m_map[date] = num;
		}
		catch (const std::exception& e) {
			std::cout  << e.what() << ": " << line <<  "\n";
		}
		line = "";
	}


}

bool storeInt(int &num, const std::string& var, std::size_t max = std::string::npos) {
	size_t fail = var.find_first_of(" ");
	(void)fail;
	char c;
	if (var.length() > max)
	{
		return (false);
	}
	std::stringstream ss;
	ss << var;
	if (!(ss >> num)) {
		return (false);
		// std::cout << var << "it is not a number\n";
	}
	if (ss >> c) {
		return (false);
		// std::cout << var << "it is not a number\n";
	}
	return (true);
}



void BitcoinExchange::checkDate(const std::string& date) {
	std::size_t pos = 0;
	std::string year_str = split(date, '-', pos);
	std::string month_str = split(date, '-', pos);
	std::string day_str(date, pos);

	int year;
	int month;
	int day;

	if (!storeInt(year, year_str, 4) ||
		!storeInt(month, month_str, 2) ||
		!storeInt(day, day_str, 2)) {
		throw (std::runtime_error("bad input"));
	}
}

void BitcoinExchange::checkValue(float &num, const std::string& value, std::string&err) {
	if (value.empty()) {
			throw (std::runtime_error("bad input"));
		}
	char *ptr;
	num = std::strtof(value.c_str(), &ptr);
	if (errno == ERANGE || num > static_cast<float>(INT_MAX)) {
		throw (std::runtime_error("out of range"));
	}
	if (*ptr != '\0')
	{
		throw (std::runtime_error("bad input"));
	}
	else if (num < 0) {
		throw (std::runtime_error("not a positive number"));
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "BitcoinExchange copy assigment operator called\n";
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << "BitcoinExchange destroctor called\n";
}
