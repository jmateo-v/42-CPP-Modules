/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:45:24 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/29 14:14:09 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("Unnamed"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap default constructor called\n";
}
ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Name constructor called: " << name << " ClapTrap\n";
}
ClapTrap::ClapTrap(const ClapTrap& other)
: _name(other._name), _hp(other._hp), _ep(other._ep), _ad(other._ad)
{
	std::cout << "Claptrap copy constructor called\n";	
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_ad = other._ad;
	}
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap destructor called\n";
}
void ClapTrap::attack(const std::string& target)
{
	if (_ep <= 0)
	{
		std::cout << "ClapTrap " <<_name << " has no energy to attack...\n";
		return ;
	}
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " << _name
				  <<  " cannot attack because is dead, think about it.\n";
		return;
	}
	_ep--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _ad << " points of damage!\n";
	 
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " <<_name << " is already dead!\n";
		return ;
	}
	_hp -= amount;
	if (_hp < 0)
		_hp = 0;
	
	std::cout << "ClapTrap " << _name << " takes " << amount
			  << " points of damage!\n";
	if (_hp == 0)
		std::cout << "ClapTrap " << _name << " is no more!\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " <<_name << " is dead, so no repairing.\n";
		return ;
	}
	if (_ep <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to repair!\n";
		return ;
	}
	_ep--;
	_hp += amount;
	
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount
			  << " HP points!\n";
}