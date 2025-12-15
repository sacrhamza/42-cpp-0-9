#include "./Fixed.hpp"

Fixed::Fixed(void)
{
  std::cout << "Default constructor called\n";
  num = 0;
}

Fixed::Fixed(const Fixed &other)
{
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
  std::cout << "Copy assignment operator called\n";
  num = other.getRawBits();

  return (*this);
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
  std::cout << "getRawBits member function called\n";
  return (num);
}

void Fixed::setRawBits(int const raw)
{
  num = raw;
}
