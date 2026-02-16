/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:53:54 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/16 16:14:20 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat bob("Bob", 140);
        Bureaucrat alice("Alice", 1);
        Bureaucrat mid("Mid", 50);

        std::cout << "\n===== SHRUBBERY TEST =====\n";
        {
            ShrubberyCreationForm shrub("home");

            std::cout << shrub << std::endl;

            std::cout << "\n--- Bob tries to execute (not signed) ---\n";
            bob.executeForm(shrub);

            std::cout << "\n--- Bob tries to sign (grade too low) ---\n";
            bob.signForm(shrub);

            std::cout << "\n--- Alice signs the form ---\n";
            alice.signForm(shrub);

            std::cout << "\n--- Bob tries to execute (grade too low) ---\n";
            bob.executeForm(shrub);

            std::cout << "\n--- Alice executes the form ---\n";
            alice.executeForm(shrub);
        }

        std::cout << "\n===== ROBOTOMY TEST =====\n";
        {
            RobotomyRequestForm robo("Bender");

            std::cout << robo << std::endl;

            std::cout << "\n--- Mid tries to execute (not signed) ---\n";
            mid.executeForm(robo);

            std::cout << "\n--- Mid signs the form ---\n";
            mid.signForm(robo);

            std::cout << "\n--- Mid executes the form (50% chance) ---\n";
            mid.executeForm(robo);

            std::cout << "\n--- Alice executes the form (also 50% chance) ---\n";
            alice.executeForm(robo);
        }

        std::cout << "\n===== PRESIDENTIAL PARDON TEST =====\n";
        {
            PresidentialPardonForm pardon("Ford Prefect");

            std::cout << pardon << std::endl;

            std::cout << "\n--- Mid tries to sign (too low) ---\n";
            mid.signForm(pardon);

            std::cout << "\n--- Alice signs the form ---\n";
            alice.signForm(pardon);

            std::cout << "\n--- Mid tries to execute (too low) ---\n";
            mid.executeForm(pardon);

            std::cout << "\n--- Alice executes the form ---\n";
            alice.executeForm(pardon);
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
