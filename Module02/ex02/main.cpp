/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:16:41 by dogs              #+#    #+#             */
/*   Updated: 2025/12/21 13:40:25 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a(10);
    Fixed b(20);
    Fixed c(10);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    std::cout << "\n--- Comparison Tests ---\n";
    std::cout << "a < b  : " << (a < b) << std::endl;
    std::cout << "a > b  : " << (a > b) << std::endl;
    std::cout << "a <= c : " << (a <= c) << std::endl;
    std::cout << "a >= c : " << (a >= c) << std::endl;
    std::cout << "a == c : " << (a == c) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;

    std::cout << "\n--- Arithmetic Tests ---\n";
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "b - a = " << (b - a) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "b / a = " << (b / a) << std::endl;

    std::cout << "\n--- Increment / Decrement Tests ---\n";
    Fixed x(5.5f);

    std::cout << "x       = " << x << std::endl;
    std::cout << "++x     = " << ++x << std::endl;
    std::cout << "x++     = " << x++ << std::endl;
    std::cout << "x after = " << x << std::endl;

    std::cout << "--x     = " << --x << std::endl;
    std::cout << "x--     = " << x-- << std::endl;
    std::cout << "x after = " << x << std::endl;

    std::cout << "\n--- Min / Max Tests ---\n";
    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    const Fixed y(3);
    const Fixed z(7);
    
    std::cout << "const min(y, z) = " << Fixed::min(y, z) << std::endl;
    std::cout << "const max(y, z) = " << Fixed::max(y, z) << std::endl;
    return 0;
}

