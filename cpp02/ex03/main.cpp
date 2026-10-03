#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point A(0, 10);
	Point B(-8, -6);
	Point C(8, 0);

	bool insdie =  bsp(A, B, C, Point(1, 0));
	bool not_inside =  bsp(A, B, C, Point(-5, -5));
	bool on_edge =  bsp(A, B, C, Point(0, -3));
	bool is_vertex = bsp(A, B, C, Point(0, -3)) ;

	std::cout << "inside: " << insdie << "\n";
	std::cout << "not inside: " << not_inside << "\n";
	std::cout << "on_edge: " << on_edge << "\n";
	std::cout << "is_vertex: " << is_vertex << "\n";
  return 0;
}
