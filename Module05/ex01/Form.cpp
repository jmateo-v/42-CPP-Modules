/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:18:15 by dogs              #+#    #+#             */
/*   Updated: 2026/02/15 12:50:12 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _signReq(150), _execReq(150)
{}
Form::Form(const std::string& name, const int signReq, const int execReq)
: _name(name), _signed(false), _signReq(signReq), _execReq(execReq)
{
    if (signReq < 1 || execReq < 1)
        throw GradeTooHighException();
    if (signReq > 150 || execReq > 150)
        throw GradeTooLowException();
}
Form::Form(const Form& other)
: _name(other._name), _signed(other._signed), _signReq(other._signReq), _execReq(other._execReq)
{}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
}
Form::~Form()
{}

const std::string& Form::getName() const
{ return _name;}
bool Form::isSigned() const
{return _signed;}
int Form::getSignReq() const
{return _signReq;}
int Form::getExecReq() const
{return _execReq;}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _signReq)
        throw GradeTooLowException();
    _signed = true;
}
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form \"" << f.getName() << "\" | signed: "
    << (f.isSigned() ? "yes" : "no")
    << " | sign grade: " << f.getSignReq()
    << " | exec grade: " << f.getExecReq();
    return os;
}