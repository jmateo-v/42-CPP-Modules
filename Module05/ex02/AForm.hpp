/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:56:10 by dogs              #+#    #+#             */
/*   Updated: 2026/02/16 17:11:51 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <ostream>

class AForm
{
private:
    std::string const _name;
    bool _signed;
    const int _signReq;
    const int _execReq;
public:
    AForm();
    AForm(const std::string& name, const int signReq, const int execReq);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool isSigned() const;
    int getSignReq() const;
    int getExecReq() const;

    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const& executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif