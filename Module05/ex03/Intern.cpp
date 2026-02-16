/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:27:14 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/16 17:09:19 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}
Intern::Intern(const Intern& other)
{
	(void)other;
}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
Intern::~Intern()
{}
static AForm* createShrub(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobo(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string formNames[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"	
	};

	AForm* (*constructors[3])(const std::string&) =
	{
		&createShrub,
		&createRobo,
		&createPardon
	};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return constructors[i](target);
		}
	}
	std::cout << "Intern: unknown form \"" << name << "\"" << std::endl;
	return NULL;
}