#include "Span.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX 20000

// void print(const std::vector<int>& vec) {
// 	for (std::size_t i = 0; i < vec.size(); i++)
// 		std::cout << vec[i] << " ";
// }

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	Span sp1(MAX);
	std::vector<int> vec;
	vec.reserve(MAX);
	srand(std::time(NULL));

	for (std::size_t i = 0; i < MAX; ++i) {
		vec.push_back(rand());
	}

	sp1.addRange<std::vector<int>::iterator >(vec.begin(), vec.end());
	std::cout << "\n";

	std::cout << sp1.longestSpan() << "\n";
	std::cout << sp1.shortestSpan() << "\n";
	return 0;
}
