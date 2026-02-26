/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:08:32 by dogs              #+#    #+#             */
/*   Updated: 2026/02/26 11:14:53 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
int main (int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid number of or malformed args\n"
        << "Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn;
        int result = rpn.solve(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}