/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:52:25 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/17 11:15:58 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>

static bool isPseudoFloat(const std::string &s)
{
	return (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff");
}
static bool isPseudoDouble(const std::string &s)
{
	return (s == "nan" || s == "+inf" || s == "-inf" || s == "inf");
}
static bool isInt(const std::string &s)
{
	char *end;
	std::strtol(s.c_str(), &end, 10);
	return(*end == '\0');
}
static bool isFloat(const std::string &s)
{
	char *end;
	std::strtof(s.c_str(), &end);
	return(*end == 'f' && *(end + 1) == '\0');
}
static bool isDouble(const std::string &s)
{
	char *end;
	std::strtod(s.c_str(), &end);
	return(*end == '\0');
}
static void handleChar(char c)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}
static void handlePseudoFloat(const std::string &s)
{
    float f = std::strtof(s.c_str(), NULL);

    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << s << "\n";
  	std::cout << "double: ";
    if (s == "+inff")
	{
        std::cout << "+";
	}
	std::cout << static_cast<double>(f) << "\n";
    
}

static void handlePseudoDouble(const std::string &s)
{
    double d = std::strtod(s.c_str(), NULL);

    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: ";
	if (s == "+inf")
	{
		std::cout << "+";
	}
	std::cout << static_cast<float>(d) << "f\n";
    std::cout << "double: " << s << "\n";
}
static void handleInt(const std::string& s)
{
	long l = std::strtol(s.c_str(), NULL, 10);
	if ( l < std::numeric_limits<int>::min()
		|| l > std::numeric_limits<int>::max())
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;	
	}
	int i = static_cast<int>(l);
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}
static void handleFloat(const std::string &s)
{
	char *end;
	float f = std::strtof(s.c_str(), &end);

	if (std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible\n";
	else if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	if (std::isnan(f) || std::isinf(f)
		|| f < std::numeric_limits<int>::min()
		|| f > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}
static void handleDouble(const std::string &s)
{
    char *end;
    double d = std::strtod(s.c_str(), &end);

    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible\n";
    else if (d >= 32 && d <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'\n";
    else
        std::cout << "char: Non displayable\n";
    if (std::isnan(d) || std::isinf(d)
		|| d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(d) << "\n";
    std::cout << "float: " << static_cast<float>(d) << "f\n";
    std::cout << "double: " << d << "\n";
}
void ScalarConverter::convert(std::string const& literal)
{
	std::cout << std::fixed << std::setprecision(1);
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return handleChar(literal[0]);
	if (isPseudoFloat(literal))
		return handlePseudoFloat(literal);
	if (isPseudoDouble(literal))
		return handlePseudoDouble(literal);
	if (isInt(literal))
		return handleInt(literal);
	if (isFloat(literal))
		return handleFloat(literal);
	if (isDouble(literal))
		return handleDouble(literal);
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}