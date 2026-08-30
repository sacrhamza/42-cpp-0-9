#include<iostream>
#include "PmergeMe.hpp"

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
	PmergeMe hey;
	std::vector<int> odd = vec;

	hey.mergeInsertion(vec, 1);


	std::cout << "size = " << odd.size() << "\n";
	std::cout << "num = " << PmergeMe::num << "\n";
	std::sort(odd.begin(), odd.end());

	hey.print(vec, "result");
	return (hey.isSorted(vec));

	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
		return (20);
	}
	return (0);
}
