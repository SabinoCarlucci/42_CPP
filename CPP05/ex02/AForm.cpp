/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:34:26 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/07 18:39:08 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include <iostream>
#include <string>

//costructors
AForm::AForm() :name("paperclip_request"), gradeToSign(150), gradeToExec(150)
{
	this->isSigned = false;
	std::cout << "Created " << *this << std::endl;
}

AForm::AForm(std::string startName, int gradeToSign, int gradeToExec) :name(startName), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	this->isSigned = false;
	std::cout << "Created " << *this << std::endl;
}

AForm::AForm(const AForm &other) :name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	std::cout << "Copied " << *this << std::endl;
}
//costructors

//destructors
AForm::~AForm()
{
	std::cout << "Scrapped " << *this << std::endl;
}


//operators
std::ostream& 		operator<<(std::ostream& os, const AForm& form)
{
	/*<name> form
	grade to sign [<grade>]
	grade to exec [<grade>]
	signed [<isSigned>]
	*/
	os << form.getName() << " form" << std::endl;
	os << "grade to sign [" << form.getGradeToSign() << "]" << std::endl;
	os << "grade to exec [" << form.getGradeToExec() << "]" << std::endl;
	std::string isSigned = form.getIsSigned() ? "yes" : "no";
	os << "signed [" << isSigned << "]" << std::endl;
	return (os);
}

AForm& AForm::operator=(const AForm& form)
{
	this->isSigned = form.isSigned;
	return (*this);
}
//operators


//getters
std::string		AForm::getName() const
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
}
//getters


//exceptions
const char* AForm::GradeTooHighException::what() const throw() { return "grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "grade too low"; }
//exceptions


void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}