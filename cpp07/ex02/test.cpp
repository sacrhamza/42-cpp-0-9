#include<iostream>
#include<vector>

int main(void){
	std::vector<int> vec;
	std::vector<int> em;
	vec.push_back(20);
	vec.push_back(20);
	vec.push_back(20);
	vec.push_back(20);
	vec.push_back(20);

	em.push_back(20);

	std::cout << vec.capacity() << "\n";

	std::cout << em.capacity() << '\n';
	em = vec;

	std::cout << em.capacity() << '\n';

	std::vector<std::string> b;

	return (0);
}
