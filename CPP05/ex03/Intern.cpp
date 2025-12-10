/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:28:03 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/10 17:19:37 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& Intern)
{
	return (*this);
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	
}