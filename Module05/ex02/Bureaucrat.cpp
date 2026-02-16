/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:24:05 by dogs              #+#    #+#             */
/*   Updated: 2026/02/16 15:03:38 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
Bureaucrat::Bureaucrat() :_name("Default"), _grade(150)
{}
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :_name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}
Bureaucrat::~Bureaucrat()
{}

const std::string& Bureaucrat::getName() const {return _name;}
int Bureaucrat::getGrade() const {return _grade;}

void Bureaucrat::increaseGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::decreaseGrade()
{
    if(_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << f.getName()
        << " because " << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const& f) const
{
    try
    {
        f.execute(*this);
        std::cout << getName() << " executed " << f.getName() << std::endl; 
    }
        
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn’t execute "
        << f.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}