/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:59:37 by dogs              #+#    #+#             */
/*   Updated: 2025/11/25 17:21:17 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int     contactCount;
	int     index;
public:
	PhoneBook();

	void    addContact(const Contact& contact);
	void    displayContacts() const;
	void    displayContact(int index) const;
};

#endif