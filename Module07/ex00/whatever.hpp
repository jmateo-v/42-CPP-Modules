/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:25:17 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/18 15:57:34 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
template <typename T>
const T& min(const T &a, const T &b)
{
	return (a < b ? a : b);
		
}
template <typename T>
const T& max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif