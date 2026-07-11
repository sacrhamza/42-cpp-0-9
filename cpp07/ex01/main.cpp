#include<iostream>
#include"iter.hpp"

template<typename T> void print(T elem) {
	// elem = 2;
	std::cout << elem << "\n";
}

int main(void){
	int arr[] = {1, 2, 3};
	iter(arr, 3, print);
	return (0);
}
