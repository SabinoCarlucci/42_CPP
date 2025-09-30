/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:36:01 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/30 18:53:51 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//constructors
Bureaucrat::Bureaucrat(std::string startName, unsigned int startGrade) :name(startName)
{
	//if con i throw per gradi sbagliati
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
std::ostream&	operator<<(std::ostream& os, Bureaucrat& bureaucrat)
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


unsigned int	Bureaucrat::getGrade()
{
	return (this->grade);
}

std::string		Bureaucrat::getName()
{
	return (this->name);
}

void				Bureaucrat::incrementGrade()
{
	this->grade--;
}

void				Bureaucrat::decrementGrade()
{
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high"; }