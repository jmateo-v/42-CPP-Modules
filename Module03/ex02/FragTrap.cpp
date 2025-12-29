/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:36:47 by dogs              #+#    #+#             */
/*   Updated: 2025/12/29 12:46:31 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hp = 100;
    _ep = 100;
    _ad = 30;
    std::cout << "FragTrap name constructor [" <<name<< "] called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " wants to high five!" << std::endl; 
}