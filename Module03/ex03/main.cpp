/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:19:41 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/29 14:25:56 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n=== DIAMONDTRAP BASIC TESTS ===\n";
    {
        DiamondTrap d("D14M0ND");

        d.attack("target dummy");
        d.takeDamage(20);
        d.beRepaired(10);

        d.whoAmI();
    }

    std::cout << "\n=== DIAMONDTRAP COPY TESTS ===\n";
    {
        DiamondTrap original("OR1G1N4L");
        DiamondTrap copy(original);

        copy.whoAmI();
        copy.attack("copy-target");
    }

    std::cout << "\n=== DIAMONDTRAP ASSIGNMENT TESTS ===\n";
    {
        DiamondTrap a("ALPH4");
        DiamondTrap b("BR4V0");

        b = a;

        b.whoAmI();
        b.attack("assigned-target");
    }

    std::cout << "\n=== END OF DIAMONDTRAP TESTS ===\n\n";
    return 0;
}




