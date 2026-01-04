/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:44:03 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/30 17:47:38 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._storage[i])
            _storage[i] = other._storage[i]->clone();
        else
            _storage[i] = NULL;
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _storage[i];
            _storage[i] = NULL;
        }
        for (int i = 0; i < 4; i++)
        {
            if (other._storage[i])
                _storage[i] = other._storage[i]->clone();
            else
                _storage[i] = NULL;
        }
    }
    return *this;
}
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _storage[i];
}
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (_storage[i] == NULL)
        {
            _storage[i] = m;
            return;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_storage[i] && _storage[i]->getType() == type)
            return _storage[i]->clone();
    }
    return NULL;
}
