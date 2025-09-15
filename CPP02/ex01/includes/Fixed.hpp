/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:44 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/15 21:09:44 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					numberValue;
		static const int	numberOfFractionalBits = 8;

	public:
		//default constructor
		Fixed();

		//copy constructor
		Fixed(const Fixed &other) ;
		
		//Int constructor 
		Fixed(const int intValue);

		//Float constructor 
		Fixed(const float floatValue);

		//copy assignment operator overload
		Fixed &operator=(const Fixed &other);

		//destructor
		~Fixed();

		int getRawBits( void ) const;

		void setRawBits( int const raw );

		//converts the fixed-point value to a floating-point value
		float toFloat( void ) const;

		//converts the fixed-point value to an integer value
		int toInt( void ) const;
		
};

//inserts a floating-point representation of the fixed-point number
std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif