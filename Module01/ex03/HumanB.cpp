/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:34:35 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 18:41:53 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
    : _name(name), _weapon(NULL)
{}
HumanB::~HumanB()
{}
void HumanB::attack() const
{
    if (_weapon)
        std::cout   << _name << " attacks with their "
                    << _weapon->getType() << std::endl;
    else
        std::cout <<_name << " is throwing fists" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}