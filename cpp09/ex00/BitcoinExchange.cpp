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
#include <string>

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {}

std::string split(const std::string& str, char c, std::size_t& pos) {
	std::size_t char_pos = str.find(c, pos);

	if (char_pos == std::string::npos) {
		throw (std::runtime_error("not valid format"));
	}
	std::string res(str, pos, char_pos - pos);
	pos = char_pos + 1;

	return (res);
}

BitcoinExchange::BitcoinExchange() {
	std::ifstream database("./data.csv");
	std::string line;
	float num;
	std::string date;
	std::size_t pos;
	std::getline(database, line);
	if (line != "date,exchange_rate")
		throw ("first like != date,exchange_rate");
	line.clear();
	while (std::getline(database, line).good()) {
		pos = 0;
		date = split(line, ',', pos);
		std::string value(line, pos);
		checkDate(date);
		checkValue(num, value);
		m_map[date] = num;
		line = "";
	}
}

void BitcoinExchange::exchange(const std::string& file_name) {
	std::ifstream file(file_name.c_str());
	if (!file.is_open()) {
		throw (std::runtime_error("cant open file: " + file_name));
	}

	std::string line;
	float num;
	std::string date;
	std::size_t pos;
	std::map<std::string, float>::const_iterator it;
	std::getline(file, line);
	if (line != "data | value")
		throw ("first like != data | value");
	line.clear();
	while (std::getline(file, line).good()) {
		pos = 0;
		try {
			date = split(line, ' ', pos);
			checkDate(date);
			std::string value_break = split(line, ' ', pos);
			if (value_break != "|")
				throw (std::runtime_error("no break"));
			std::string value(line, pos);
			checkValue(num, value);
			if (num < 0 || num > 1000)
				throw (std::runtime_error("value must be an integer or float between 0 and 100"));
			it = m_map.find(date);
			if (it == m_map.end()) {
				it = m_map.upper_bound(date);
				if (it == m_map.end()) {
					throw (std::runtime_error("there is no value lower"));
				}
			}
			std::cout << it->first << " => " << num << " => " << (it->second * num) << "\n";
		}
		catch (const std::exception& e) {
			std::cout  << "Error: " << e.what() << ": " << line <<  "\n";
		}
		line = "";
	}
}

bool storeInt(int &num, const std::string& var, std::size_t max = std::string::npos) {
	char c;
	if (var.length() != max)
	{
		return (false);
	}
	std::stringstream ss;
	if (var.find_first_not_of("0123456789") != std::string::npos)
		return (false);
	ss << var;
	if (!(ss >> num)) {
		return (false);
	}
	if (ss >> c) {
		return (false);
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
			!storeInt(month, month_str, 2) || month > 12||
			!storeInt(day, day_str, 2) || day > 31 ) {
		throw (std::runtime_error("bad input"));
	}
}

void BitcoinExchange::checkValue(float &num, const std::string& value) {
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
