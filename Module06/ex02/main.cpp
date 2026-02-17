/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:42:25 by dogs              #+#    #+#             */
/*   Updated: 2026/02/17 12:43:51 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(NULL));

    Base* ptr = generate();

    std::cout << "identify(Base*): ";
    identify(ptr);

    std::cout << "identify(Base&): ";
    identify(*ptr);

    delete ptr;
    return 0;
}
