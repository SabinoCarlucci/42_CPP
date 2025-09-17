/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:29:19 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 20:40:43 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "[Brain] standard constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "[Brain] copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return "index must be included between 0 and 99";
	return this->ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << "index must be included between 0 and 99" << std::endl;
		return;
	}
	this->ideas[index] = idea;
}