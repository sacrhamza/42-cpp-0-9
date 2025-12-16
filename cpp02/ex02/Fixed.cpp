#include "./Fixed.hpp"

int Fixed::fractional_bit;

Fixed::Fixed(void)
{
  // std::cout << "Default constructor called\n";
  m_num = 0;
}

Fixed::Fixed(const Fixed &other)
{
  // std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed::Fixed(int num)
{
  // std::cout << "Int constructor called\n";
  fractional_bit = 8;
  m_num = (num << fractional_bit) | ((num < 0) << 31);
}

Fixed::Fixed(const float num)
{
  // std::cout << "Float constructor called\n";
  fractional_bit = 8;
  m_num = int(roundf(num * (1 << fractional_bit)));
}


Fixed& Fixed::operator=(const Fixed &other)
{
  // std::cout << "Copy assignment operator called\n";
  m_num = other.m_num;

  return (*this);
}

Fixed::~Fixed(void)
{
  // std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
  // std::cout << "getRawBits member function called\n";
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
  return (m_num + other.m_num);
}

Fixed Fixed::operator-(const Fixed &other) const
{
  return (m_num - other.m_num);
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
  std::cout << "m_num = " << m_num << " other.m_num = " << other.m_num << "\n";
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
