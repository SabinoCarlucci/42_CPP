/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:21:33 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/05 19:28:34 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"
#include <iostream>
#include <string>

//costructors
Form::Form() :name("paperclip_request"), gradeToSign(150), gradeToExec(150)
{
	this->isSigned = false;
	std::cout << "Created " << *this << std::endl;
}

Form::Form(std::string startName, int gradeToSign, int gradeToExec) :name(startName), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	this->isSigned = false;
	std::cout << "Created " << *this << std::endl;
}

Form::Form(const Form &other) :name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	std::cout << "Copied " << *this << std::endl;
}
//costructors

//destructors
Form::~Form()
{
	std::cout << "Scrapped " << *this << std::endl;
}


//operators
std::ostream& 		operator<<(std::ostream& os, const Form& form)
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

Form& Form::operator=(const Form& form)
{
	this->isSigned = form.isSigned;
	return (*this);
}
//operators


//getters
std::string		Form::getName() const
{
	return (this->name);
}

bool		Form::getIsSigned() const
{
	return (this->isSigned);
}

int		Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int		Form::getGradeToExec() const
{
	return (this->gradeToExec);
}
//getters


//exceptions
const char* Form::GradeTooHighException::what() const throw() { return "grade too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "grade too low"; }
//exceptions


void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}