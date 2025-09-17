/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:15 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 14:59:03 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <math.h> // for roundf
#include "../includes/Fixed.hpp"

Fixed::Fixed() : numberValue(0)
{
	std::cout << "Default constructor called" <<std::endl;
}

//Int constructor 
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" <<std::endl;
	numberValue = intValue << numberOfFractionalBits;
}

//Float constructor 
Fixed::Fixed(const float floatValue) : numberValue(static_cast<int>(roundf(floatValue * (1 << numberOfFractionalBits))))
{
	std::cout << "Float constructor called" <<std::endl;
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

/*inserts a floating-point representation of the fixed-point number
 into the output stream object passed as a parameter*/
std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
    return os;
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

float Fixed::toFloat( void ) const
{
	return static_cast<float>(numberValue) / (1 << numberOfFractionalBits);
}

int Fixed::toInt( void ) const
{
	return numberValue >> numberOfFractionalBits;
}