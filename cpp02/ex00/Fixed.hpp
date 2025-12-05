#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
  private:
    int num;
    static int fractional_bit;
  public:
    Fixed(void);
    Fixed(const Fixed &other);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

Fixed::Fixed(void)
{
  num = 0;
}


Fixed::Fixed(const Fixed &other)
{
  std::cout << "Copy constructor called\n";
  num = other.getRawBits();
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
  std::cout << "getRawBits member function called";
  return (num);
}

void Fixed::setRawBits(int const raw)
{
  num = raw;
}


#endif
