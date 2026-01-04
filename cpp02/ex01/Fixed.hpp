#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <ostream>
#include <cmath>

class Fixed
{
  private:
    int m_num;
    const static int fractional_bit;

  public:
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed(int num);
    Fixed(const float num);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed& operator=(const Fixed &other);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};


std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif
