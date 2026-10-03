#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
  private:
    int num;
    const static int fractional_bit;

  public:
    Fixed(void);
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed &other);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};


#endif
