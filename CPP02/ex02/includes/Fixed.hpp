/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:44 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 00:13:46 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					numberValue;
		static const int	numberOfFractionalBits = 8;

	public:

	/*----------------------------˅˅˅ constructors/destructors ˅˅˅-----------------*/
		//default constructor
		Fixed();

		//copy constructor
		Fixed(const Fixed &other) ;
		
		//Int constructor 
		Fixed(const int intValue);

		//Float constructor 
		Fixed(const float floatValue);

		//destructor
		~Fixed();
	/*----------------------------^^^ constructors/destructors ^^^-----------------*/
	
	
	/*-----------------------˅˅˅ comparison operators ˅˅˅--------------------------------*/
	
		//copy assignment operator overload
		Fixed &operator=(const Fixed &other);

		//comparison operators overloads
		bool operator>(const Fixed &other) const;

		bool operator<(const Fixed &other) const;

		bool operator>=(const Fixed &other) const;

		bool operator<=(const Fixed &other) const;

		bool operator==(const Fixed &other) const;

		bool operator!=(const Fixed &other) const;
	/*-----------------------^^^ comparison operators ^^^--------------------------------*/


	/*-----------------------˅˅˅ arithmetic operators ˅˅˅--------------------------------*/
		Fixed operator+(const Fixed &other) const;

		Fixed operator-(const Fixed &other) const;

		Fixed operator*(const Fixed &other) const;

		Fixed operator/(const Fixed &other) const;

	/*-----------------------^^^ arithmetic operators ^^^--------------------------------*/

	
	/*-----------------------˅˅˅ increment/decrement operators ˅˅˅--------------------------------*/
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
	/*-----------------------^^^ increment/decrement operators ^^^--------------------------------*/

	
	/*-----------------------˅˅˅ getter/setter ˅˅˅--------------------------------*/
		int getRawBits( void ) const;

		void setRawBits( int const raw );
	/*-----------------------^^^ getter/setter ^^^--------------------------------*/

	
	/*-----------------------˅˅˅ convert to int/float ˅˅˅--------------------------------*/
		//converts the fixed-point value to a floating-point value
		float toFloat( void ) const;

		//converts the fixed-point value to an integer value
		int toInt( void ) const;
	/*-----------------------^^^ convert to int/float ^^^--------------------------------*/

	
	/*-----------------------˅˅˅ min/max ˅˅˅--------------------------------*/
		static Fixed &min(Fixed &first, Fixed &second);

		static const Fixed &min(const Fixed &first, const Fixed &second);

		static Fixed &max(Fixed &first, Fixed &second);

		static const Fixed &max(const Fixed &first, const Fixed &second);
	
	/*-----------------------^^^ min/max ^^^--------------------------------*/
		
};

//inserts a floating-point representation of the fixed-point number
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif