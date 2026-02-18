/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:11:38 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/18 19:12:27 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::cout << "=== Testing std::vector ===\n";

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(42);
    vec.push_back(100);

    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found in vector: " << *it << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Vector error: " << e.what() << "\n";
    }

    try {
        easyfind(vec, 999);
    }
    catch (const std::exception& e) {
        std::cout << "Vector error: " << e.what() << "\n";
    }

    std::cout << "\n=== Testing std::list ===\n";

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);

    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found in list: " << *it << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "List error: " << e.what() << "\n";
    }

    try {
        easyfind(lst, 999);
    }
    catch (const std::exception& e) {
        std::cout << "List error: " << e.what() << "\n";
    }

    return 0;
}
