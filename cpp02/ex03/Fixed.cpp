#include "./Fixed.hpp"

const int Fixed::fractional_bit = 8;

Fixed::Fixed(void)
{
  m_num = 0;
}

Fixed::Fixed(const Fixed &other)
{
  *this = other;
}

Fixed::Fixed(int num)
{
  m_num = (num * (1 << fractional_bit));
}

Fixed::Fixed(const float num)
{
  m_num = int(roundf(num * (1 << fractional_bit)));
}


Fixed& Fixed::operator=(const Fixed &other)
{
  m_num = other.m_num;

  return (*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
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


Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed tmp;

	tmp.setRawBits(m_num + other.m_num);
  return (tmp);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed tmp;

	tmp.setRawBits(m_num - other.m_num);
  return (tmp);
}

Fixed& Fixed::operator--(void)
{
  m_num--;
  return (*this);
}

Fixed& Fixed::operator++(void)
{
  m_num++;
  return (*this);
}

Fixed Fixed::operator--(int)
{
  Fixed tmp = (*this);

  --(*this);
  return (tmp);
}

Fixed Fixed::operator++(int)
{
  Fixed tmp = (*this);

  ++(*this);
  return (tmp);
}


Fixed Fixed::operator*(const Fixed& other) const
{
  Fixed tmp;

  tmp.setRawBits((m_num * other.m_num) / (1 << fractional_bit));
  return (tmp);
}

Fixed Fixed::operator/(const Fixed& other) const
{
  Fixed tmp;

  tmp.setRawBits(m_num * (1 << fractional_bit) / other.m_num);
  return (tmp);
}

bool Fixed::operator>(const Fixed &other) const
{
  return (m_num > other.m_num);
}

bool Fixed::operator<(const Fixed &other) const
{
  return (m_num < other.m_num);
}

bool Fixed::operator>=(const Fixed &other) const
{
  return (m_num >= other.m_num);
}

bool Fixed::operator<=(const Fixed &other) const
{
  return (m_num <= other.m_num);
}

bool Fixed::operator==(const Fixed &other) const
{
  return (m_num == other.m_num);
}

bool Fixed::operator!=(const Fixed &other) const
{
  return (m_num != other.m_num);
}

Fixed& Fixed::max(Fixed &first, Fixed &second)
{
  if (first > second)
    return (first);
  return (second);
}

const Fixed& Fixed::max(const Fixed &first, const Fixed &second)
{
  if (first > second)
    return (first);
  return (second);
}

Fixed& Fixed::min(Fixed &first, Fixed &second)
{
  if (first < second)
    return (first);
  return (second);
}

const Fixed& Fixed::min(const Fixed &first, const Fixed &second)
{
  if (first < second)
    return (first);
  return (second);
}
