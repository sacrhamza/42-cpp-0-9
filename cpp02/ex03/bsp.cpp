#include "Point.hpp"

Fixed area(Point const A, Point const B, Point const C)
{
	Fixed triangle_area = (A.get_x() * (B.get_y() - C.get_y()))
												+ (B.get_x() * (C.get_y() - A.get_y()))
												+ (C.get_x() * (A.get_y() - B.get_y()));	

	return (Fixed(std::fabs(triangle_area.toFloat())) * Fixed(0.5f));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle_area = area(a, b, c);
	Fixed APC = area(a, point, c);
	Fixed APB = area(a, point, b);
	Fixed CPB = area(c, point, b);

	if (APC == 0 || APB == 0 || CPB == 0)
		return (false);

	return (triangle_area == (APC + APB + CPB));
}
