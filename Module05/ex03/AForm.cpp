/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:18:15 by dogs              #+#    #+#             */
/*   Updated: 2026/02/16 17:11:32 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _signReq(150), _execReq(150)
{}
AForm::AForm(const std::string& name, const int signReq, const int execReq)
: _name(name), _signed(false), _signReq(signReq), _execReq(execReq)
{
    if (signReq < 1 || execReq < 1)
        throw GradeTooHighException();
    if (signReq > 150 || execReq > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other)
: _name(other._name), _signed(other._signed), _signReq(other._signReq), _execReq(other._execReq)
{}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}
AForm::~AForm()
{}

const std::string& AForm::getName() const
{ return _name;}
bool AForm::isSigned() const
{return _signed;}
int AForm::getSignReq() const
{return _signReq;}
int AForm::getExecReq() const
{return _execReq;}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _signReq)
        throw GradeTooLowException();
    _signed = true;
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low";
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form: Not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form \"" << f.getName() << "\" | signed: "
    << (f.isSigned() ? "yes" : "no")
    << " | sign grade: " << f.getSignReq()
    << " | exec grade: " << f.getExecReq();
    return os;
}