/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:59:09 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/18 14:59:37 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T &x)
{
    std::cout << x << " ";
}

int main()
{
    int arrInt[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(arrInt, 5, printElement<int>);
    std::cout << std::endl;

    std::string arrStr[] = {"hello", "world", "42", "cpp"};
    std::cout << "String array: ";
    iter(arrStr, 4, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
