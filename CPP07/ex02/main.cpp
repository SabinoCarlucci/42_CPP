/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:46:52 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/19 18:55:43 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 10;

		Array<int> b = a; // copy costructor
		b[0] = 42;

		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;

		Array<int> c;
		c = a; // assignment
		c[1] = 999;

		std::cout << "a[1] = " << a[1] << std::endl;
		std::cout << "c[1] = " << c[1] << std::endl;

		std::cout << a[10] << std::endl; // exception
	}
	catch(const std::exception&)
	{
		std::cerr << "Exception: out of bounds" << std::endl;
	}
	return (0);
}