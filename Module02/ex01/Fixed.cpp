/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:16:55 by dogs              #+#    #+#             */
/*   Updated: 2025/12/20 18:26:20 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
:_rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}