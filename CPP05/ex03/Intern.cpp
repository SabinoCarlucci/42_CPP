/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:28:03 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/16 11:08:26 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"


Intern::Intern() 
{
	forms["robotomy request"] = &Intern::createRobotomy;
	forms["pardon request"] = &Intern::createPresidential;
	forms["shrubbery request"] = &Intern::createShrubbery;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

AForm* Intern::createRobotomy(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubbery(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

const char* Intern::UnknownFormException::what() const throw() { return "Form Unknown"; }

AForm* Intern::makeForm(std::string formName, std::string target)
{
	if (forms.find(formName) != forms.end())
	{
		std::cout << "Intern creates " << formName << std::endl;
		return (this->*forms[formName])(target);
	}
	else
		throw UnknownFormException();
	return (NULL);
}