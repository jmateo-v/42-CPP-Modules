/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmateo-v <jmateo-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:23:55 by jmateo-v          #+#    #+#             */
/*   Updated: 2026/02/16 16:26:21 by jmateo-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>
class Intern
{
public:
	 Intern();
	 Intern(const Intern& other);
	 Intern& operator=(const Intern& other);
	 ~Intern();

	 AForm* makeForm(const std::string& name, const std::string& target);
};

#endif