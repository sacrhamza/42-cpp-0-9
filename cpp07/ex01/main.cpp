#include<iostream>
#include"iter.hpp"

template<typename T> void print(T& elem) {
	std::cout << elem << "\n";
}

int main(void){
	int arr[] = {1, 2, 3};
	iter<int, void (*)(int&) >(arr, 3, print<int>);

	const char arrChar[] = {'1', '2', '3'};
	typedef void (*FuncType)(const char&);

	iter<const char, FuncType>(arrChar, 3, &print);

	const float arrFloat[] = {1.337f, 1.338, 1339};

	typedef void (*FuncTypeFloat)(const float&);
	iter<const float, FuncTypeFloat>(arrFloat, 3, print);

	iter<const float>(arrFloat, 3, print<const float>);
	iter(arrFloat, 3, print<const float>);
	return (0);
}
