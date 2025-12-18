/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:36:56 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/15 16:29:19 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Generic ShrubberyCreationForm", 145, 137), target("something") 
{
	std::cout << "Created " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string		target) : AForm("Generic ShrubberyCreationForm", 145, 137), target(target) 
{
	std::cout << "Created " << *this << std::endl;
}

//destructors
ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << "Scrapped " << *this << std::endl;
}

//getters
std::string		ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}
//getters

//operators
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	AForm::operator=(form);
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) 
	: AForm(other), target(other.target)
{
	std::cout << "Copied " << *this << std::endl;
}

void		ShrubberyCreationForm::doTheThing() const
{
	std::string filename = this->target + "_shrubbery";

	std::ofstream MyFile(filename.c_str());
	
	MyFile << "   ^   " << std::endl;
    MyFile << "  /|\\  " << std::endl;
    MyFile << " /_|_\\ " << std::endl;
    MyFile << "   |   " << std::endl;

	MyFile.close();
	std::cout << filename << " file created in working directory" << std::endl;
}