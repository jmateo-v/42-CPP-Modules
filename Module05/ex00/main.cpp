/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:51:44 by dogs              #+#    #+#             */
/*   Updated: 2026/02/09 13:52:44 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.increaseGrade();
        std::cout << a << std::endl;

        a.increaseGrade();
        std::cout << a << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;

    try {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;

        b.decreaseGrade();
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----" << std::endl;

    try {
        Bureaucrat c("Charlie", 0);
        std::cout << c << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
