/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:54:40 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 17:20:12 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    Zombie *horde = zombieHorde(N, "Jackson");
    for (int i = 0; i < N; i++)
        horde[i].announce();
    
    delete[] horde;
    return (0);
}