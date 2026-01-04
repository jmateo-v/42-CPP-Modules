/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:05:00 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/30 16:19:20 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
: _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
Character::Character(std::string const& name)
: _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
Character::Character(const Character& other)
:_name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for(int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}
std::string const& Character::getName() const
{
	return _name;
}
void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
		return;
	_inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
	if(idx < 0 || idx > 4)
		return;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}