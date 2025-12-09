/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:48:08 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/09 18:47:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>
#include <sstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("something")
{
	std::cout << "Created " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string		target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "Created " << *this << std::endl;
}

//destructors
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Scrapped " << *this << std::endl;
}

//getters
/* std::string		AForm::getName() const
{
	return (this->name);
}

bool		AForm::getIsSigned() const
{
	return (this->isSigned);
}

int		AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int		AForm::getGradeToExec() const
{
	return (this->gradeToExec);
} */

std::string		PresidentialPardonForm::getTarget() const
{
	return (this->target);
}
//getters

//operators
/* std::ostream& 		operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	os << form.getName() << " form" << std::endl;
	os << "grade to sign [" << form.getGradeToSign() << "]" << std::endl;
	os << "grade to exec [" << form.getGradeToExec() << "]" << std::endl;
	std::string isSigned = form.getIsSigned() ? "yes" : "no";
	os << "signed [" << isSigned << "]" << std::endl;
	return (os);
} */

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
	AForm::operator=(form);
	return (*this);
}

void		PresidentialPardonForm::doTheThing() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox"; 
}