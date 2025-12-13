/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:31:45 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 18:40:48 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(const std::string& name);
    ~HumanB();
    void attack() const;
    void setWeapon(Weapon& weapon);


private:
    std::string _name;
    Weapon* _weapon;
};
#endif