/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:48:08 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/15 16:28:10 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()

RobotomyRequestForm::RobotomyRequestForm() : AForm("Generic RobotomyRequestForm", 72, 45), target("something") 
{
	std::cout << "Created " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string		target) : AForm("Generic RobotomyRequestForm", 72, 45), target(target) 
{
	std::cout << "Created " << *this << std::endl;
}

//destructors
RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "Scrapped " << *this << std::endl;
}

//getters
std::string		RobotomyRequestForm::getTarget() const
{
	return (this->target);
}
//getters

//operators
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
	AForm::operator=(form);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) 
	: AForm(other), target(other.target)
{
	std::cout << "Copied " << *this << std::endl;
}

void		RobotomyRequestForm::doTheThing() const
{
	// Get a different random number each time the program runs
  	srand(time(0));
  
  	// Generate a random number between 0 and 100
  	int randomNum = rand() % 2;
	
	std::cout << "* DRILLING NOISE *" << std::endl;
	if (randomNum == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " 's robotomy failed" << std::endl;
}