/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:15 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/15 23:55:49 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <math.h> // for roundf
#include "../includes/Fixed.hpp"

/*----------------------------˅˅˅ constructors/destructors ˅˅˅-----------------*/
Fixed::Fixed() : numberValue(0)
{
	//std::cout << "Default constructor called" <<std::endl;
}

//Int constructor 
Fixed::Fixed(const int intValue)
{
	//std::cout << "Int constructor called" <<std::endl;
	numberValue = intValue << numberOfFractionalBits;
}

//Float constructor 
Fixed::Fixed(const float floatValue) : numberValue(static_cast<int>(roundf(floatValue * (1 << numberOfFractionalBits))))
{
	//std::cout << "Float constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" <<std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" <<std::endl;
}
/*----------------------------^^^ constructors/destructors ^^^-----------------*/


/*----------------------------˅˅˅ operators ˅˅˅--------------------------------*/

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &other)
		numberValue = other.getRawBits();
	return *this;
}

//comparison operators overloads
bool Fixed::operator>(const Fixed &other) const
{
	return this->numberValue > other.numberValue;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->numberValue < other.numberValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->numberValue >= other.numberValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->numberValue <= other.numberValue;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->numberValue == other.numberValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->numberValue != other.numberValue;
}
/*----------------------------^^^ operators ^^^--------------------------------*/

/*-----------------------˅˅˅ arithmetic operators ˅˅˅--------------------------------*/

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.numberValue == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

/*-----------------------^^^ arithmetic operators ^^^--------------------------------*/


/*-----------------------˅˅˅ increment/decrement operators ˅˅˅--------------------------------*/
Fixed &Fixed::operator++()
{
	++numberValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++numberValue;
	return temp;
}

Fixed &Fixed::operator--()
{
	--numberValue;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--numberValue;
	return temp;
}
/*-----------------------^^^ increment/decrement operators ^^^--------------------------------*/


/*-----------------------˅˅˅ getter/setter ˅˅˅--------------------------------*/
int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" <<std::endl;
	return numberValue;
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" <<std::endl;
	numberValue = raw;
}
/*-----------------------^^^ getter/setter ^^^--------------------------------*/


/*-----------------------˅˅˅ convert to int/float ˅˅˅--------------------------------*/
float Fixed::toFloat( void ) const
{
	return static_cast<float>(numberValue) / (1 << numberOfFractionalBits);
}

int Fixed::toInt( void ) const
{
	return numberValue >> numberOfFractionalBits;
}
/*-----------------------^^^ convert to int/float ^^^--------------------------------*/


/*-----------------------˅˅˅ min/max ˅˅˅--------------------------------*/
Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first < second ? first : second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first < second ? first : second);
}

 Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first > second ? first : second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first > second ? first : second);
}
/*-----------------------^^^ min/max ^^^--------------------------------*/


/*inserts a floating-point representation of the fixed-point number
 into the output stream object passed as a parameter*/
std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat(); // non posso usarlo
    return os;
}