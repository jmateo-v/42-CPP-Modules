/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:50:02 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/24 15:03:38 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _data;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename It>
	void addRange(It begin, It end)
	{
		if(std::distance(begin, end) > (int)(_maxSize - _data.size()))
			throw std::runtime_error("Not enough space for range");
		_data.insert(_data.end(), begin, end);
	}
};

#endif