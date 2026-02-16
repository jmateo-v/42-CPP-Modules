/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:20:34 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/16 16:15:41 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target)
{}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecReq())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
	{
		std::cerr << "Error: could not create shrubbery file";
	}
	file <<
		"              v .   ._, |_  .,\n"
		"           `-._\\/  .  \\ /    |/_\n"
		"               \\\\  _\\, y | \\//\n"
		"         _\\_.___\\\\, \\\\/ -.\\||\n"
		"           `7-,--.`._||  / / ,\n"
		"          /'     `-. `./ / |/_.'\n"
		"                     |    |//\n"
		"                     |_    /\n"
		"                     |-   |\n"
		"                     |   =|\n"
		"                     |    |\n"
		"--------------------/ ,  . \\--------._\n";
	file.close();
}