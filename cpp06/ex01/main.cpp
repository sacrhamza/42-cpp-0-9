#include"Serializer.hpp"

int main(void){

	Data some("Serializer");
	uintptr_t b = Serializer::serialize(&some);
	std::cout << Serializer::deserialize(b)->getData();

	return (0);
}
