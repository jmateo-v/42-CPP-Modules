/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:37:14 by dogs              #+#    #+#             */
/*   Updated: 2026/02/26 11:05:56 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <stack>
#include <sstream>
#include <cctype>

RPN::RPN()
{}
RPN::RPN(const RPN& other)
{(void)other;}
RPN& RPN::operator=(const RPN& other)
{
        if (this != &other)
        {}
        return *this;
}
RPN::~RPN()
{}

bool RPN::isOperator(char c)
{
    return(c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::operate(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by 0");
            return a / b;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::solve(const std::string& argv)
{
    std::stack<int> stack;
    std::stringstream input(argv);
    std::string token;

    while (input >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
            stack.push(token[0] - '0');
        else if (token.size() == 1 && isOperator(token[0]))
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough args");
            
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            int result = operate(a, b, token[0]);
            stack.push(result);
        }
        else
            throw std::runtime_error("Error: invalid token");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    return stack.top();
}