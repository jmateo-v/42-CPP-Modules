/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:12:00 by dogs              #+#    #+#             */
/*   Updated: 2025/12/29 14:17:46 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("DiamondTrap_clap_name"), ScavTrap("DiamondTrap"), FragTrap("DiamondTrap"), _name("DiamondTrap")
{
    _hp = FragTrap::_hp;
    _ep = ScavTrap::_ep;
    _ad = FragTrap::_ad;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hp = FragTrap::_hp;
    _ep = ScavTrap::_ep;
    _ad = FragTrap::_ad;
    std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}
void DiamondTrap::whoAmI()
{
    std::cout << "I am" << _name
    << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}