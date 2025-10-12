/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:36:01 by scarlucc          #+#    #+#             */
/*   Updated: 2025/10/11 19:36:13 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//constructors
Bureaucrat::Bureaucrat(std::string startName, int startGrade) :name(startName)
{
	if (startGrade < 1)
		throw GradeTooHighException();
	if (startGrade > 150)
		throw GradeTooLowException();
	this->grade = startGrade;
	std::cout << "Created " << *this << std::endl;
}

Bureaucrat::Bureaucrat() :name("Fantozzi")
{
	this->grade = 150;
	std::cout << "Created " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :name(other.name), grade(other.grade)
{
	std::cout << "Copied" << *this << std::endl;
}
//constructors


Bureaucrat::~Bureaucrat()
{
	std::cout << "Terminated " << *this << std::endl;
}


//operators
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	//<name>, bureaucrat grade <grade>.
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()<< ".";
	return (os);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.grade;
	return (*this);
}
//operators


int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string		Bureaucrat::getName() const
{
	return (this->name);
}

void				Bureaucrat::incrementGrade()
{
	if ((this->grade - 1) < 1)
		throw GradeTooHighException();
	this->grade--;
}

void				Bureaucrat::decrementGrade()
{
	if ((this->grade + 1) > 150)
		throw GradeTooLowException();
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "grade too low"; }