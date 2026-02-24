/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:36:13 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/24 16:15:12 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private: 
	T *_data;
	unsigned int _size;
public:
	Array();
	Array(unsigned int size);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;
	unsigned int size() const;
};

#include "Array.tpp"

#endif