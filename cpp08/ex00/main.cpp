#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <set>

int main(void) {

	std::vector<int> vec;

	vec.push_back(20);
	vec.push_back(100);
	vec.push_back(300);

	std::list<int> mylist(vec.begin(), vec.end());
	std::set<int> myset(vec.begin(), vec.end());

	if (easyfind(mylist, 20) != mylist.end())
		std::cout << "my list has 20\n";

	if (easyfind<std::set<int> >(myset, 200) == myset.end())
		std::cout << "my set does not have 200\n";

}
