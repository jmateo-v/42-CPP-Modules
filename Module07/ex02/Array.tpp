/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:43:30 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/18 16:27:27 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{}
template <typename T>
Array<T>::Array(unsigned int size) : _data(new T[size]()), _size(size)
{}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0)
{
	*this = other;
}
template <typename T>
Array<T> &Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _data[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _data[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}