/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:18:53 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 22:35:52 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "[Cat] standard constructor called" << std::endl;
}
Cat::Cat(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[Cat] copy constructor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "[Cat] destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "MEOW" << std::endl;
}