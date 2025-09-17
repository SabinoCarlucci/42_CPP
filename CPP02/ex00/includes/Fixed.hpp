/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:44 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 14:51:59 by scarlucc         ###   ########.fr       */
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

		//copy assignment operator overload
		Fixed &operator=(const Fixed &other);

		//destructor
		~Fixed();

		//get numberValue
		int getRawBits( void ) const;

		//set numberValue
		void setRawBits( int const raw );
};

#endif