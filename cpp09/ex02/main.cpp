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

		std::vector<int> sorted = Vec;
		std::sort(sorted.begin(), sorted.end());

		PmergeMeVec vecSort;
		PmergeMeDeque dequeSort;

		printNums(Vec.begin(), Vec.end(), "before");

	struct timespec begin_time, end_time;

	clock_gettime(CLOCK_MONOTONIC, &begin_time);
		vecSort.mergeInsertion(Vec, 1);
	clock_gettime(CLOCK_MONOTONIC, &end_time);
		printNums(Vec.begin(), Vec.end(), "after");
	
		std::cout << "Time to process a range of " << Vec.size()
			<< " elements with std::vector: "
			<< ((end_time.tv_sec - begin_time.tv_sec) * 1000000000 + end_time.tv_nsec - begin_time.tv_nsec) / 1000 << "us" << "\n";


clock_gettime(CLOCK_MONOTONIC, &begin_time);
		dequeSort.mergeInsertion(Deque, 1);
clock_gettime(CLOCK_MONOTONIC, &end_time);
		std::cout << "Time to process a range of " 
			<< Deque.size() <<  " elements with std::deque: "
			<< ((end_time.tv_sec - begin_time.tv_sec) * 1000000000 + end_time.tv_nsec - begin_time.tv_nsec) / 1000 << "us" << "\n";

	if (! std::equal(sorted.begin(), sorted.end(), Vec.begin()) ||
			! std::equal(sorted.begin(), sorted.end(), Deque.begin()))
		return (1);

	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
		return (1);
	}
	return (0);
}
