/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:09:47 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 23:10:30 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "../includes/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "[WrongCat] standard constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[WrongCat] copy constructor called" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "MOOOOO" << std::endl;
}