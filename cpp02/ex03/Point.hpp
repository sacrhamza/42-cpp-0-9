#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point(void);
		Point(const float px, const float py);
		Point(const Point& other);
		const Point& operator=(const Point &other);
		~Point(void);
		const Fixed& get_x() const;
		const Fixed& get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
