/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:58:47 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/18 19:07:41 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), target);
	if (iter == container.end())
		throw std::runtime_error("Value not found");
	return iter;
}

#endif