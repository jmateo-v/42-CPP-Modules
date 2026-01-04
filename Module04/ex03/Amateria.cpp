/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:20:07 by jmateo-v          #+#    #+#             */
/*   Updated: 2025/12/30 15:38:58 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
: _type("")
{}
AMateria::AMateria(std::string const& type)
: _type(type)
{}
AMateria::AMateria(const AMateria& other)
: _type(other._type)
{}
AMateria& AMateria::operator=(const AMateria& other)
{
	if(this != &other)
		_type = other._type;
	return *this;
}
AMateria::~AMateria()
{}
std::string const & AMateria::getType() const
{
	return _type;
}
void AMateria::use(ICharacter& target)
{
    (void)target;
}
