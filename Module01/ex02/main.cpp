/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:29:10 by dogs              #+#    #+#             */
/*   Updated: 2025/12/13 17:44:42 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF= str;

    std::cout << "str memory adress is: " << &str << std::endl;
    std::cout << "stringPTR memory adress is: " << stringPTR << std::endl;
    std::cout << "stringREF memory adress is: " << &stringREF << std::endl;

    std::cout << "str value is: " << str << std::endl;
    std::cout << "stringPTR points to value: " << *stringPTR << std::endl;
    std::cout << "stringREF points to value: " << stringREF << std::endl;
    
    return 0;
}