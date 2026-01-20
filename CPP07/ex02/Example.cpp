/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:20:45 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/20 16:53:13 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Example.hpp"
#include <ostream>

Example::Example() :someNumber(42)
{
	
}

Example::Example(const Example &other) :someNumber(other.someNumber)
{
	
}

Example::~Example()
{
	
}

Example &Example::operator=(const Example &other)
{
	if (this != &other)
	{
		this->someNumber = other.someNumber;
	}
	return (*this);
}

int Example::getSomeNumber() const
{
	return someNumber;
}

void Example::setSomeNumber(int newNumber)
{
	someNumber = newNumber;
}

std::ostream &operator<<(std::ostream &os, const Example &other)
{
	os << "Example object someNumber: " << other.getSomeNumber() << std::endl;
	return os;
}