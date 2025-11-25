/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:11:32 by dogs              #+#    #+#             */
/*   Updated: 2025/11/25 17:53:25 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	contactCount = 0;
	index = 0;
}

static std::string truncate(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::addContact(const Contact& contact)
{
	contacts[index] = contact;
	index = (index + 1) % 8;
	if (contactCount < 8)
		contactCount++;
}
void PhoneBook::displayContacts() const
{
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
	std::cout	<< std::setw(10) << i << "|"
				<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
				<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
				<< std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}
}
void PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}