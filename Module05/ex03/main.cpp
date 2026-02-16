/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:53:54 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/16 17:10:01 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        std::cout << "\n===== VALID FORMS =====\n";

        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robo  = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        if (shrub)
        {
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
            delete shrub;
        }

        if (robo)
        {
            boss.signForm(*robo);
            boss.executeForm(*robo);
            delete robo;
        }

        if (pardon)
        {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }

        std::cout << "\n===== INVALID FORM =====\n";

        AForm* wrong = someRandomIntern.makeForm("not a real form", "nobody");
        if (wrong)
            delete wrong;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
