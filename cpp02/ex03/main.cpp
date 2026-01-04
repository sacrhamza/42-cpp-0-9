#include <iostream>
#include "Point.hpp"

int main( void )
{
	bool insdie =  bsp(Point(0, 2), Point(1, 0), Point(0, 0), Point(0.5f, 0.5));
	bool not_inside =  bsp(Point(0, 2), Point(1, 0), Point(0, 0), Point(0.5f, 0.5));
	bool on_edge =  bsp(Point(0, 2), Point(1, 0), Point(0, 0), Point(0.5f, 0.5));
	bool is_vertex =  bsp(Point(0, 2), Point(1, 0), Point(0, 0), Point(0.5f, 0.5));

	std::cout << insdie << "\n";
	std::cout << not_inside << "\n";
	std::cout << on_edge << "\n";
	std::cout << is_vertex << "\n";
  return 0;
}
