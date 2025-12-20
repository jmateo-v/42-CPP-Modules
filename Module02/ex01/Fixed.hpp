/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:17:27 by dogs              #+#    #+#             */
/*   Updated: 2025/12/20 18:22:48 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int value);
    Fixed (const float value);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    int toInt(void) const;
    float toFloat(void) const;
    
private:
    int _rawBits;
    static const int _fractionalBits = 8;
};

std::ostream& operator <<(std::ostream& out, const Fixed& fixed);

#endif