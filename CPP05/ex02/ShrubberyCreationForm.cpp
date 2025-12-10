/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:36:56 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/10 12:25:22 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("something") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string		target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

//destructors
ShrubberyCreationForm::~ShrubberyCreationForm() {}

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