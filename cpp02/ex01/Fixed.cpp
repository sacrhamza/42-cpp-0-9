#include "./Fixed.hpp"

void print_bit(unsigned char bit)
{
  for (int i = 0; i < 8; i++)
  {
    std::cout << (bit >> 7);
    bit = bit << 1;
  }
}

void print_int_bits(int var)
{
  for (size_t i = 0; i < sizeof(var); i++)
  {
    print_bit(*((unsigned char*)&var + (sizeof(var) - i - 1)));
  }
}

int Fixed::fractional_bit;

Fixed::Fixed(void)
{
  std::cout << "Default constructor called\n";
  m_num = 0;
}

Fixed::Fixed(const Fixed &other)
{
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed::Fixed(int num)
{
  std::cout << "Int constructor called\n";
  fractional_bit = 8;
  m_num = (num << fractional_bit) | ((num < 0) << 31);
}

Fixed::Fixed(const float num)
{
  std::cout << "Float constructor called\n";
  fractional_bit = 8;
  m_num = int(roundf(num * (1 << fractional_bit)));
}


Fixed& Fixed::operator=(const Fixed &other)
{
  std::cout << "Copy assignment operator called\n";
  m_num = other.m_num;

  return (*this);
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
  std::cout << "getRawBits member function called\n";
  return (m_num);
}

void Fixed::setRawBits(int const raw)
{
  m_num = raw;
}

float Fixed::toFloat(void) const
{
  return (float(m_num) / (1 << fractional_bit));
}


int Fixed::toInt(void) const
{
  return (m_num / (1 << fractional_bit));
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
  return (out << other.toFloat());
}
