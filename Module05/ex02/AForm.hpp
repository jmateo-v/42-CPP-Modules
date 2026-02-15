/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:56:10 by dogs              #+#    #+#             */
/*   Updated: 2026/02/15 13:13:16 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>
#include <ostream>

class Form
{
private:
    std::string const _name;
    bool _signed;
    const int _signReq;
    const int _execReq;
public:
    Form();
    Form(const std::string& name, const int signReq, const int execReq);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif