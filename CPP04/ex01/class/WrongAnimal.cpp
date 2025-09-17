/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:07:42 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 23:09:09 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "../includes/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "[WrongAnimal] standard constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[WrongAnimal] copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] makes a wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const 
{
	return this->type;
}

void WrongAnimal::setType(std::string newType)
{
	this->type = newType;
}
