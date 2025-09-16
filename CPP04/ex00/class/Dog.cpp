/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:16:34 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 22:35:46 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "[Dog] standard constructor called" << std::endl;
}
Dog::Dog(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[Dog] copy constructor called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "[Dog] destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "BARK!" << std::endl;
}