/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:44 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/15 18:08:51 by scarlucc         ###   ########.fr       */
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

		int getRawBits( void ) const;

		void setRawBits( int const raw );
};

#endif