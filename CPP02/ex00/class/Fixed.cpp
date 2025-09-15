/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:15 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/15 19:33:40 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "../includes/Fixed.hpp"

Fixed::Fixed() : numberValue(0)
{
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &other)
		numberValue = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" <<std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return numberValue;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" <<std::endl;
	numberValue = raw;
}