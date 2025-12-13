/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:53:53 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 17:12:53 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie();
    ~Zombie();
    void announce(void) const;
    void setName(std::string name);
private:
    std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif