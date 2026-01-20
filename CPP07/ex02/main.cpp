/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:46:52 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/20 17:35:09 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"
#include "Example.hpp"
#include <iostream>

int main()
{
	try
	{
		//empty array
		Array<int> nothing;
		Array<int> nothingAgain(0);
		
		
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 10;

		Array<int> b(a); // copy costructor
		b[0] = 42;

		std::cout << "a[0] = " << a[0] << std::endl;
		std::cout << "b[0] = " << b[0] << std::endl;

		Array<int> c;
		c = a; // assignment
		c[1] = 999;

		std::cout << "a[1] = " << a[1] << std::endl;
		std::cout << "c[1] = " << c[1] << std::endl;

		//constant array
		const Array<int> constArray(c);
		for (unsigned int i = 0; i < constArray.size(); i++)
			std::cout << "constArray[" << i << "] = " << constArray[i] << std::endl;

		// constArray[0] = 123; // compilation error


		//complex type
		unsigned int iter = 3;
		Array<Example> classExample(iter);
		classExample[1].setSomeNumber(24);
		classExample[2].setSomeNumber(666);
		for (unsigned int i = 0; i < iter; i++)
			std::cout << classExample[i];

		//std::cout << a[10] << std::endl; // exception
	}
	catch(const std::exception&)
	{
		std::cerr << "Exception: out of bounds" << std::endl;
	}
	return (0);
}