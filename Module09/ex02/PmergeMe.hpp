/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:28:44 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/03/03 15:20:58 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	
	void sortVector(std::vector<int>& vec);
	void sortDeque(std::deque<int>& deq);
private:
	static bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
	template<typename T>
	void fordJohnson(T& container)
	{
		if (container.size() <= 1)
			return ;
		std::vector<std::pair<int, int> > pairs;
		pairs.reserve(container.size() / 2);

		typename T::iterator it = container.begin();
		while (it != container.end())
		{
			int first = *it;
			++it;
			if (it != container.end())
			{
				int second = *it;
				++it;

				if (first < second)
					pairs.push_back(std::make_pair(first, second));
				else
					pairs.push_back(std::make_pair(second, first));
			}
			else
			{
				pairs.push_back(std::make_pair(first, first));
			}
		}
		std::sort(pairs.begin(), pairs.end(), comparePairs);

		T main;
		T pend;

		for (size_t i = 0; i < pairs.size(); i++)
		{
			int small = pairs[i].first;
			int big = pairs[i].second;

			if (small == big)
				pend.push_back(small);
			else
			{
				main.push_back(big);
				pend.push_back(small);
			}
		}
		for (typename T::iterator pit = pend.begin(); pit != pend.end(); pit++)
			binaryInsert(main, *pit);
		
		container.assign(main.begin(), main.end());
	}

	template<typename T>
	void binaryInsert(T& main, int value)
	{
		typename T::iterator it = std::lower_bound(main.begin(), main.end(), value);
		main.insert(it, value);
	}
};

#endif