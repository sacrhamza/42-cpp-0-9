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
    static Fixed& min(Fixed &first, Fixed &second);
    static const Fixed& min(const Fixed &first, const Fixed &second);
    static Fixed& max(Fixed &first, Fixed &second);
    static const Fixed& max(const Fixed &first, const Fixed &second);

    Fixed(void);
    Fixed(const Fixed &other);
    Fixed(const int num);
    Fixed(const float num);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed& operator=(const Fixed &other);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // operators

    // >, <, >=, <=, ==, !=
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // +, -, *, /
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // ++var, var++, --var, var--
    Fixed& operator--(void);
    Fixed& operator++(void);
    Fixed operator--(int);
    Fixed operator++(int);
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);

#endif
