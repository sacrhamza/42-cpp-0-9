#include<iostream>
#include"iter.hpp"

template<typename T> void print(T elem) {
	std::cout << elem << "\n";
	elem = 2;
}

int main(void){
	int arr[] = {1, 2, 3};
	iter(arr, 3, print);
	return (0);
}
