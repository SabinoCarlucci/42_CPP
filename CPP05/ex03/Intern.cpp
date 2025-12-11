/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:28:03 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/11 18:28:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"


Intern::Intern() {}

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
	std::map<std::string, AForm* (Intern::*)(std::string const &target)> forms;
	forms["robotomy request"] = &Intern::createRobotomy;
	forms["pardon request"] = &Intern::createPresidential;
	forms["shrubbery request"] = &Intern::createShrubbery;

	try
	{
		if (forms.find(formName) != forms.end())
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*forms[formName])(target);
		}
		else
			throw UnknownFormException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (NULL);
}