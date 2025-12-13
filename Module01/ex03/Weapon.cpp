/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:09:31 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 18:16:06 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& name)
: _type(name)
{}

Weapon::~Weapon()
{}
const std::string& Weapon::getType() const
{return _type;}
void Weapon::setType(const std::string& type)
{
    _type = type;
}