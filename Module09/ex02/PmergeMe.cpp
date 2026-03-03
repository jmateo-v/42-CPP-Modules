/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:34:52 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/03/03 14:59:04 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>

PmergeMe::PmergeMe()
{}
PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{}
	return *this;
}
PmergeMe::~PmergeMe()
{}

bool PmergeMe::comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.second < b.second;
}

void PmergeMe::sortVector(std::vector<int>& vec)
{
	fordJohnson(vec);
}
void PmergeMe::sortDeque(std::deque<int>& deq)
{
	fordJohnson(deq);
}