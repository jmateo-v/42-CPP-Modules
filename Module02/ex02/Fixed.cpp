/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:16:55 by dogs              #+#    #+#             */
/*   Updated: 2025/12/21 13:35:19 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
:_rawBits(0)
{}
Fixed::Fixed(const int value)
{
     _rawBits = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
    _rawBits = roundf(value * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits(void) const
{
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

int Fixed::toInt(void) const
{
    return _rawBits >> _fractionalBits;
}

float Fixed::toFloat(void) const
{
    return (float)_rawBits /  (1 << _fractionalBits);
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->_rawBits > other._rawBits;
}
bool Fixed::operator<(const Fixed& other) const
{
    return this->_rawBits < other._rawBits;
}
bool Fixed::operator>=(const Fixed& other) const
{
    return this->_rawBits >= other._rawBits;
}
bool Fixed::operator<=(const Fixed& other) const
{
    return this->_rawBits<= other._rawBits;
}
bool Fixed::operator==(const Fixed& other) const
{
    return this->_rawBits == other._rawBits;
}
bool Fixed::operator!=(const Fixed& other) const
{
    return this->_rawBits != other._rawBits;
}
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_rawBits + other._rawBits);
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_rawBits - other._rawBits);
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long tmp = (long)this->_rawBits * (long)other._rawBits;
    result.setRawBits(tmp >> _fractionalBits);
    return result;
}
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    long tmp = ((long)this->_rawBits << _fractionalBits) / (long)other._rawBits;
    result.setRawBits(tmp);
    return result;
}
Fixed& Fixed::operator++()
{
    this->_rawBits++;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_rawBits++;
    return temp;
}
Fixed& Fixed::operator--()
{
    this->_rawBits--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_rawBits--;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}