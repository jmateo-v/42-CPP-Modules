/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:17:33 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 18:22:46 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();
    void attack() const;

private:
    std::string _name;
    Weapon& _weapon;
};

#endif