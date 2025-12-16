#include "Point.hpp"


Point::Point(void) : x(0) ,y(0) {}
Point::Point(const float px, const float py) : x(px), y(py) {}
Point::Point(const Point& other) : x(other.x), y(other.y){}
const Point& Point::operator=(const Point &other)
{
	return (other);
}

Point::~Point(void){}
