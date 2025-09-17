/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:18:53 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 21:21:23 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "[Cat] standard constructor called" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other)
{
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "[Cat] copy constructor called" << std::endl;
}
Cat::~Cat()
{
	delete this->brain;
	std::cout << "[Cat] destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}