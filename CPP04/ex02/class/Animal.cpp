/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:49:12 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 22:12:23 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "[animal] standard constructor called" << std::endl;
}
Animal::Animal(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[animal] copy constructor called" << std::endl;
}
Animal::~Animal()
{
	std::cout << "[animal] destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[animal] assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

//Animal diventa virtuale, quindi non ha questa implementazione
/* void Animal::makeSound() const
{
	std::cout << "[animal] makes a sound" << std::endl;
} */

std::string Animal::getType() const 
{
	return this->type;
}

void Animal::setType(std::string newType)
{
	this->type = newType;
}
