/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:19:41 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/29 12:52:40 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== CLAPTRAP TESTS ===\n";
    {
        ClapTrap c("CL4P-TR4P");
        c.attack("target dummy");
        c.takeDamage(5);
        c.beRepaired(3);
        c.takeDamage(20);
        c.attack("nobody");
        c.beRepaired(10);
    }

    std::cout << "\n=== SCAVTRAP TESTS ===\n";
    {
        ScavTrap s("SC4V-TR4P");
        s.attack("bandit");
        s.takeDamage(30);
        s.beRepaired(20);
        s.guardGate();
    }

    std::cout << "\n=== FRAGTRAP BASIC TESTS ===\n";
    {
        FragTrap f("FR4G-TR4P");
        f.attack("psycho");
        f.takeDamage(40);
        f.beRepaired(25);
        f.highFivesGuys();
    }

    std::cout << "\n=== END OF TESTS ===\n\n";
    return 0;
}



