/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:21:53 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 17:21:54 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie * heapZombie = newZombie("Heapward");
    delete heapZombie;

    randomChump("Johny J. Stackilla");
}