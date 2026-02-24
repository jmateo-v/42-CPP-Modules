/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:34:37 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/24 15:54:45 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "=== Basic test ===" << std::endl;
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "=== Exception test ===" << std::endl;
        Span small(1);
        small.addNumber(42);
        small.addNumber(21);
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
	try
    {
        Span small(1);
        small.addNumber(42);
		small.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
	try
    {
        Span small(1);
        small.addNumber(42);
		small.longestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "=== addRange test ===" << std::endl;

    try
    {
        Span sp(10);

        std::vector<int> nums;
        for (int i = 1; i <= 10; i++)
            nums.push_back(i * 3);

        sp.addRange(nums.begin(), nums.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
    std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "=== Large test (15,000 numbers) ===" << std::endl;

	try
	{
	std::srand(std::time(NULL));
    Span big(15000);

    for (int i = 0; i < 15000; i++)
        big.addNumber((rand() % 100000) + 1);

    std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << big.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
    	std::cout << "Error: " << e.what() << std::endl;
	}
    return 0;
}
