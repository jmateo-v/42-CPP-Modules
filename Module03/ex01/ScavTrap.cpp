/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:54:34 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/29 12:56:25 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap()
{
	_name = "Unnamed";
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap default constructor called\n";
}
ScavTrap::ScavTrap(const std::string& name)
: ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap named constructor [" <<name<< "] called\n";
}
ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called\n";
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}
void ScavTrap::attack(const std::string& target)
{
	if (_ep <= 0)
	{
		std::cout << "ScavTrap " <<_name << " has run out of energy\n";
		return ;
	}
	if (_hp <= 0)
	{
		std::cout << "ScavTrap " << _name
				  <<  " is too dead to bother attacking\n";
		return;
	}
	_ep--;
	std::cout << "ScavTrap " << _name << " fires a projectile to " << target
			  << ", hitting for " << _ad << " points of damage!\n";
}
void ScavTrap::guardGate()
{
	if (_hp <= 0)
		std::cout << "Death wont prevent " << _name << " from gatekeeping...\n";
    std::cout << "ScavTrap " << _name
              << " has entered Gate Keeper mode...\n";
}
