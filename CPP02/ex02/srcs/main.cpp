/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:09:38 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 00:16:24 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "../includes/Fixed.hpp"

int main( void ) {

	Fixed a(5.05f);
	std::cout << "a = " << a << std::endl;
	
	Fixed b(2);
	std::cout << "b = " << b << std::endl;

	Fixed c(a);
	std::cout << "c = " << c << std::endl;

	Fixed d(b);
	std::cout << "d = " << d << std::endl;
	std::cout << std::endl;
	
	std::cout << "------Test comparison operators------" << std::endl;
	std::cout << "a > b:  " << (a > b) << std::endl;
	std::cout << "a < b:  " << (a < b) << std::endl;
	std::cout << "a >= b:  " << (a >= b) << std::endl;
	std::cout << "a <= b:  " << (a <= b) << std::endl;
	
	std::cout << "a >= c:  " << (a >= c) << std::endl;
	std::cout << "b <= d:  " << (b <= d) << std::endl;
	
	std::cout << "a == b:  " << (a == b) << std::endl;
	std::cout << "a != b:  " << (a != b) << std::endl;
	
	
	std::cout << std::endl;
	std::cout << "------Test arithmetic operators------" << std::endl;
	std::cout << "b + d =   " << (b + d) << std::endl;
	std::cout << "a - b =  " << (a - b) << std::endl;
	std::cout << "a * b:  " << (a * b) << std::endl;
	std::cout << "b / b:  " << (b / b) << std::endl;

	std::cout << std::endl;
	std::cout << "------Test increment/decrement------" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << std::endl;

	std::cout << "c = " << c << std::endl;
	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "--b = " << --b << std::endl;
	std::cout << std::endl;
	
	std::cout << "d = " << d << std::endl;
	std::cout << "d-- = " << d-- << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << std::endl;
	

	std::cout << std::endl;
	std::cout << "------Test getter/setter------" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "(rawbits)a = " << a.getRawBits() << std::endl;
	std::cout << "cambio a" << std::endl;
	a.setRawBits(5);
	std::cout << "(rawbits)a = " << a.getRawBits() << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "(rawbits)b = " << b.getRawBits() << std::endl;
	std::cout << "cambio b" << std::endl;
	b.setRawBits(1.05f * (1 << 8));
	std::cout << "(rawbits)b = " << b.getRawBits() << std::endl;
	std::cout << "b = " << b << std::endl;
	
	std::cout << std::endl;
	std::cout << "------Test min/max------" << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << std::endl;
	
	Fixed const e(55);
	Fixed const f(42);

	std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;
	std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
	
	/* Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	*/
	return 0;
}
