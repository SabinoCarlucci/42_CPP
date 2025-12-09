/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:36:01 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/09 16:14:35 by scarlucc         ###   ########.fr       */
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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception & e)//messaggio personalizzato per grado troppo basso
	{
		//<bureaucrat> couldn’t sign <form> because <reason>.
		//std::string reason;
		std::cout << this->name 
					<< " could not sign " 
					<< form.getName() 
					<< " because " 
					<< /* reason */ e.what()
					<< std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (std::exception & e)//messaggio personalizzato per grado troppo basso
	{
		//<bureaucrat> couldn’t execute <form> because <reason>.
		//std::string reason;
		std::cout << this->name 
					<< " could not execute " 
					<< form.getName() 
					<< " because " 
					<< /* reason */ e.what()
					<< std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "grade too low"; }