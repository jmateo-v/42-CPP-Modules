/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:51:44 by dogs              #+#    #+#             */
/*   Updated: 2026/02/15 13:00:45 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat alice("Alice", 1);

        Form tax("Tax Form", 40, 20);
        Form passport("Passport Form", 1, 1);

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << tax << std::endl;
        std::cout << passport << std::endl;

        std::cout << "\n--- Bob tries to sign Tax Form (should fail) ---\n";
        bob.signForm(tax);

        std::cout << "\n--- Alice tries to sign Tax Form (should succeed) ---\n";
        alice.signForm(tax);

        std::cout << "\n--- Alice tries to sign Passport Form (should succeed) ---\n";
        alice.signForm(passport);

        std::cout << "\nFinal form states:\n";
        std::cout << tax << std::endl;
        std::cout << passport << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing invalid form creation ---\n";
    try {
        Form bad("Bad Form", 0, 10); // should throw
    }
    catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}