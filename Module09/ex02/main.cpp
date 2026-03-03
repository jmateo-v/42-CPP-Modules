/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:19:06 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/03/03 15:22:09 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "PmergeMe.hpp"

static bool isPositiveNumber(const char* s)
{
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i]))
            return false;
    return true;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: no input numbers." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++)
    {
        if (!isPositiveNumber(argv[i]))
        {
            std::cerr << "Error: invalid number '" << argv[i] << "'" << std::endl;
            return 1;
        }

        long n = std::atol(argv[i]);
        if (n < 0 || n > 2147483647)
        {
            std::cerr << "Error: number out of range '" << argv[i] << "'" << std::endl;
            return 1;
        }

        vec.push_back((int)n);
        deq.push_back((int)n);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    PmergeMe sorter;

    clock_t startVec = clock();
    sorter.sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    sorter.sortDeque(deq);
    clock_t endDeq = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    double vecTime = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
    double deqTime = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << deqTime << " us" << std::endl;

    return 0;
}
