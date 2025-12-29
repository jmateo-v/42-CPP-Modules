/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:19:41 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/22 17:47:37 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n=== CLAPTRAP TESTS ===\n";
    {
        ClapTrap a("CL4P-TR4P");
        a.attack("target dummy");
        a.takeDamage(5);
        a.beRepaired(3);
        a.takeDamage(20);
        a.attack("nobody");
        a.beRepaired(10);
    }

    std::cout << "\n=== SCAVTRAP TESTS ===\n";
    {
        ScavTrap s("SC4V-TR4P");
        s.attack("bandit");
        s.takeDamage(30);
        s.beRepaired(20);
        s.guardGate();
    }

    std::cout << "\n=== ENERGY DEPLETION TEST ===\n";
    {
        ScavTrap s("ENERGY-BOT");
        for (int i = 0; i < 55; i++)
            s.attack("dummy");
    }

    std::cout << "\n=== DEATH TEST ===\n";
    {
        ScavTrap s("DEAD-BOT");
        s.takeDamage(200);
        s.attack("ghost");
        s.beRepaired(10);
        s.guardGate();
    }

    std::cout << "\n=== END OF TESTS ===\n\n";
    return 0;
}

