#include<iostream>
#include "PmergeMe.hpp"

#include<sstream>
#include <sys/time.h>


template <typename Iter> void printNums(Iter begin, Iter end, std::string msg) {
	std::cout << msg << ": {";
	for (; begin != end; ++begin)	 {
		std::cout << *begin;
		if (begin + 1 != end)
			std::cout << " ";
	}
	std::cout << "}\n";
}

std::vector<int> parseNums(char **argv) {
	int num;
	std::vector<int> res;
	std::stringstream ss;
	for (int idx = 0; argv[idx] != NULL; ++idx) {
		ss << std::string(argv[idx]);
		if (!(ss >> num) || !ss.eof())
		{
			throw (std::runtime_error("not a number or overflow"));
		}
		if (num < 0) {
			throw (std::runtime_error("negative number"));
		}
		ss.clear();
		res.push_back(num);
	}
	return (res);	
}

int main(int argc, char **argv){
	if (argc < 2) {
		std::cerr << "./PmergeMe list_of_numbers\n";
		return (1);
	}
	try {
		std::vector<int> Vec = parseNums(argv + 1);
		std::deque<int> Deque(Vec.begin(), Vec.end());

		PmergeMeVec vecSort;
		PmergeMeDeque dequeSort;

		printNums(Vec.begin(), Vec.end(), "before");

		struct timeval begin_time, end_time;

		gettimeofday(&begin_time, NULL);
		vecSort.mergeInsertion(Vec, 1);
		gettimeofday(&end_time, NULL);
		printNums(Vec.begin(), Vec.end(), "after");

		std::cout << "Time to process a range of " << Vec.size()
			<< " elements with std::vector: "
			<< ((end_time.tv_sec - begin_time.tv_sec) * 1000000 + end_time.tv_usec - begin_time.tv_usec)<< "us" << "\n";


		gettimeofday(&begin_time, NULL);
		dequeSort.mergeInsertion(Deque, 1);
		gettimeofday(&end_time, NULL);
		std::cout << "Time to process a range of " 
			<< Deque.size() <<  " elements with std::deque: "
			<< ((end_time.tv_sec - begin_time.tv_sec) * 1000000 + end_time.tv_usec - begin_time.tv_usec)<< "us" << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
		return (1);
	}
	return (0);
}
