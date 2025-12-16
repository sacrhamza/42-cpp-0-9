#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
  private:
  const Fixed x;
  const Fixed y;
  public:
  Point(void);
  Point(const float px, const float py);
  Point(const Fixed px, const Fixed py) {}
  Point(const Point& other);
const   Point& operator=(const Point &other);
  ~Point(void);
  Point operator-(const Point other) const
  {
    return (Point((x - other.x).toFloat(), (y - other.y).toFloat()));
  }
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif
