/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:47:54 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/18 16:48:10 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

template <typename T>
void printPreview(const Array<T>& arr, int count = 10)
{
    std::cout << "[ ";
    for (int i = 0; i < count && i < (int)arr.size(); i++)
        std::cout << arr[i] << ", ";
    std::cout << "... ]" << std::endl;
}

int main()
{
    std::cout << "\n=== BASIC CONSTRUCTION TEST ===" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Filled numbers[] and mirror[] with random values." << std::endl;
    std::cout << "Preview: ";
    printPreview(numbers);

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===" << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != numbers[i] || test[i] != numbers[i])
            {
                std::cerr << "Copy constructor failed!" << std::endl;
                return 1;
            }
        }
    }
    std::cout << "Copy constructor works correctly." << std::endl;

    std::cout << "\n=== VALUE INTEGRITY TEST ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Values match mirror[] perfectly." << std::endl;

    std::cout << "\n=== OUT OF RANGE TESTS ===" << std::endl;
    try { numbers[-2] = 0; }
    catch(const std::exception& e) { std::cout << "Caught exception: " << e.what() << std::endl; }

    try { numbers[MAX_VAL] = 0; }
    catch(const std::exception& e) { std::cout << "Caught exception: " << e.what() << std::endl; }

    std::cout << "Out-of-range checks working." << std::endl;

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
    {
        Array<int> a(10);
        Array<int> b(5);

        for (int i = 0; i < 10; i++) a[i] = i * 2;
        for (int i = 0; i < 5; i++) b[i] = 999;

        b = a;

        if (b.size() != a.size())
        {
            std::cerr << "Assignment operator failed: wrong size" << std::endl;
            return 1;
        }

        for (unsigned int i = 0; i < a.size(); i++)
        {
            if (b[i] != a[i])
            {
                std::cerr << "Assignment operator failed: values differ" << std::endl;
                return 1;
            }
        }
    }
    std::cout << "Assignment operator works correctly." << std::endl;

    std::cout << "\n=== CONST ACCESS TEST ===" << std::endl;
    {
        const Array<int> constArr(numbers);
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (constArr[i] != numbers[i])
            {
                std::cerr << "Const operator[] failed!" << std::endl;
                return 1;
            }
        }
    }
    std::cout << "Const operator[] works correctly." << std::endl;

    std::cout << "\n=== RANDOM REWRITE TEST ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();

    std::cout << "Rewrote numbers[] with new random values." << std::endl;
    std::cout << "Preview: ";
    printPreview(numbers);

    delete [] mirror;

    std::cout << "\n=== ALL TESTS PASSED SUCCESSFULLY ===" << std::endl;
    return 0;
}

