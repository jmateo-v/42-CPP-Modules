/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:19:41 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/22 16:39:26 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "\n=== Aaaaand... OPEN! ===\n\n";

    ClapTrap a("who is very mean and evil looking");
    ClapTrap b("who I am very tired to think of a name k thxbye");

    std::cout << "\n-- Round 1: Basic attacks --\n";
    a.attack("I am very tired to think of a name k thxbye type");
    b.takeDamage(5);

    std::cout << "\n-- Round 2: Counterattack --\n";
    b.attack("Very mean and evil looking type");
    a.takeDamage(3);

    std::cout << "\n-- Round 3: Repairs --\n";
    a.beRepaired(4);
    b.beRepaired(2);

    std::cout << "\n-- Round 4: Big damage --\n";
    b.takeDamage(20);

    std::cout << "\n-- Round 5: Dead ClapTrap tries to act --\n";
    b.attack("Very mean and evil looking type");
    b.beRepaired(10);

    std::cout << "\n-- Round 6: Burn all energy --\n";
    for (int i = 0; i < 12; i++)
        a.attack("the air");

    std::cout << "\n-- Round 7: Try repairing with no energy --\n";
    a.beRepaired(5);

    std::cout << "\n=== Stairs... ===\n\n";
    return 0;
}
