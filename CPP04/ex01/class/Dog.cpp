/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:16:34 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 21:53:37 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "[Dog] standard constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "[Dog] copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "[Dog] destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "BARK!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->brain);
}