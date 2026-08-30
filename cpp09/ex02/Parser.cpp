#include <exception>
#include<iostream>
#include<sstream>
#include <stdexcept>
#include<vector>

std::vector<int> parseNums(char **argv) {
	int num;
	std::vector<int> res;
	std::stringstream ss;
	for (int idx = 0; argv[idx] != NULL; ++idx) {
		ss << std::string(argv[idx]);
		if (!(ss >> num) || !ss.eof() || num < 0)
		{
			throw (std::runtime_error(""));
		}
		ss.clear();
		res.push_back(num);
	}
	return (res);	
}

int main(int argc, char **argv){
	if (argc < 2)
		return (1);
	try {
		std::vector<int> vec = parseNums(argv + 1);
		std::cout << vec.size();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
		return (20);
	}
	return (0);
}
