/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:42:23 by dogs              #+#    #+#             */
/*   Updated: 2025/11/25 18:47:36 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::setContact(const std::string& fn,
					const std::string& ln,
					const std::string& nn,
					const std::string& pn,
					const std::string& ds)
{
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}
std::string Contact::getFirstName() const
{return firstName;}
std::string Contact::getLastName() const
{return lastName;}
std::string Contact::getNickname() const
{return nickname;}
std::string Contact::getPhoneNumber() const
{return phoneNumber;}
std::string Contact::getDarkestSecret() const
{return darkestSecret;}
