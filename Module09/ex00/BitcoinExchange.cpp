/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:41:10 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/24 19:38:44 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <cstdlib>


BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_db = other._db;
	return *this;
}
BitcoinExchange::~BitcoinExchange()
{}
bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	for (size_t i = 0; i < year.size(); i++)
		if (!isdigit(year[i]))
			return false;
	for (size_t i = 0; i < month.size(); i++)
		if (!isdigit(month[i]))
			return false;
	for (size_t i = 0; i < day.size(); i++)
		if (!isdigit(day[i]))
	 		return false;
	
	int nyear = std::atoi(year.c_str());
	int nmonth = std::atoi(month.c_str());
	int nday = std::atoi(day.c_str());

	if (nyear < 2009)
		return false;
	if (nmonth < 1 || nmonth > 12)
		return false;
	
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (nmonth == 2)
	{
		bool leap = (nyear % 4 == 0 && nyear %100 != 0) || (nyear % 400 == 0);
		if (leap && nday == 29)
			return true;
	}
	if (nday < 1 || nday > daysInMonth[nmonth - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const
{
	if (value.empty())
		return false;
	bool dot = false; 
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.')
		{
			if (dot == true)
				return false;
			dot = true;
		}
		else if (!isdigit(value[i]))
			return false;
	}

	double num = std::atof(value.c_str());

	if (num < 0 || num > 1000)
		return false;
	return true;
}

float BitcoinExchange::getClosestRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);

	if (it == _db.end())
		--it;
	else if (it->first != date)
	{
		if (it == _db.begin())
			throw std::runtime_error("No earlier date in database");
		--it;
	}
	return it->second;
}

void BitcoinExchange::loadDB(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: failed to open DB file");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		
		size_t comma = line.find (',');
		if (comma == std::string::npos)
			throw std::runtime_error("Error: bad database format");
		
		std::string date = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);

		if (!isValidDate(date))
			throw std::runtime_error("Error: bad date in database");
		
		char* end;
		float rate = std::strtof(rateStr.c_str(), &end);
		if (*end != '\0')
			throw std::runtime_error("Error: bad rate in database");
		_db[date] = rate;
	}
}
static void trim(std::string& s)
{
    size_t start = 0;
    while (start < s.size() && std::isspace(s[start]))
        start++;

    size_t end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        end--;

    s = s.substr(start, end - start);
}

void BitcoinExchange::printInput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");
	
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipe);
		std::string value = line.substr(pipe + 1);

		trim(date);
		trim(value);

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isValidValue(value))
		{
			double num = std::atof(value.c_str());
			if (num < 0)
				std::cout << "Error: not a positive number" << std::endl;
			else if (num > 1000)
				std::cout << "Error: too large a number" << std::endl;
			else
				std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double num = std::atof(value.c_str());
		float rate = getClosestRate(date);
		double result = num * rate;

		std::cout << date << " => " << num << " = " << result << std::endl;
	}
}
