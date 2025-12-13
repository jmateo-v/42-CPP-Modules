/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:54:06 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 17:14:06 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{}
Zombie::~Zombie()
{
    std::cout   << _name << " is no more." << std::endl;
}
void Zombie::announce(void) const
{
    std::cout   << _name << ":  BraiiiiiiinnnzzzZ..."
                << std::endl;
}
void Zombie::setName(std::string name)
{
    _name = name;
}