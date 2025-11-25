/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:53:54 by dogs              #+#    #+#             */
/*   Updated: 2025/11/25 18:41:16 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string promptField(const std::string& fieldName)
{
    std::string input;
    while (true) {
        std::cout << fieldName << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nInput closed. Exiting..." << std::endl;
            exit(0);
        }
        if (!input.empty())
            return input;
        std::cout << fieldName << " cannot be empty. Please try again." << std::endl;
    }
}

Contact createContactFromInput()
{
    std::string fn = promptField("First Name");
    std::string ln = promptField("Last Name");
    std::string nn = promptField("Nickname");
    std::string pn = promptField("Phone Number");
    std::string ds = promptField("Darkest Secret");

    Contact newContact;
    newContact.setContact(fn, ln, nn, pn, ds);
    return newContact;
}


int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "What would you like to do? (ADD, SEARCH, EXIT) ";

        if (!std::getline(std::cin, command))
        {
            std::cout << "\nInput closed. Exiting..." << std::endl;
            break;
        }
        if (command == "EXIT")
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        else if (command == "ADD")
        {
            Contact newContact = createContactFromInput();
            phoneBook.addContact(newContact);
            std::cout << "Contact added" << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "Enter index for more info: ";
            std::getline(std::cin, command);
            int index = atoi(command.c_str());
            phoneBook.displayContact(index);
        }
        else
            continue;
    }
    return 0;
}