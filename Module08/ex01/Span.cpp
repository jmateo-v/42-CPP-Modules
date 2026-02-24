/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:08:03 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/24 15:32:13 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
Span::Span()
:_maxSize(0)
{}
Span::Span(unsigned int n)
:_maxSize(n)
{}
Span::Span(const Span& other)
:_maxSize(other._maxSize), _data(other._data)
{}
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return *this;
}
Span::~Span()
{}

void Span::addNumber(int n)
{
	if (_data.size() >= _maxSize)
		throw std::runtime_error("Span is full");
	_data.push_back(n);
}

int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough numbers to find span");
	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}
int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("Not enough numbers to find span");
	std::vector<int>::const_iterator minIT = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator maxIT = std::max_element(_data.begin(), _data.end());
	return *maxIT - *minIT;
}