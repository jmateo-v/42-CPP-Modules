/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:16:41 by dogs              #+#    #+#             */
/*   Updated: 2025/12/21 14:42:49 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

// Declare bsp() so main can call it
bool bsp(Point const a, Point const b, Point const c, Point const p);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(20.0f, 20.0f);
    Point edge(5.0f, 0.0f);   // On AB edge → should be false

    std::cout << std::boolalpha;

    std::cout << "Inside test: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside test: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Edge test: " << bsp(a, b, c, edge) << std::endl;

    return 0;
}


