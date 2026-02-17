/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:39:32 by dogs              #+#    #+#             */
/*   Updated: 2026/02/17 11:41:03 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.s = "Horse";
    data.n = 42;

    std::cout << "Original pointer:      " << &data << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t:  " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer:  " << ptr << std::endl;

    std::cout << "ptr->s = " << ptr->s << std::endl;
    std::cout << "ptr->n = " << ptr->n << std::endl;

    return 0;
}
