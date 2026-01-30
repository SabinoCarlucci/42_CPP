/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:32:58 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/30 14:37:19 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "Subject example" << std::endl;
		Span sp = Span(10);//test: _maxSize > actual size
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "test with 2 numbers" << std::endl;
		Span sp = Span(2);//test: _maxSize > actual size
		sp.addNumber(6);
		sp.addNumber(3);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "test with 2 equal numbers" << std::endl;
		Span sp = Span(2);//test: _maxSize > actual size
		sp.addNumber(6);
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//test with 10000 numbers
	/* try
	{
		std::cout << "My example" << std::endl;
		int howManyNumbers = 10000;
		std::vector<int> big;
		for (int i = 0; i < howManyNumbers; ++i)
		{
			std::cout << i << std::endl;
			big.push_back(i);
		}
		std::cout << std::endl;
		
		std::cout << "My example" << std::endl;
		//int test = howManyNumbers -1; //test exception
		//Span sp(test); //will throw exception because has one less number than big span from above
		Span sp(howManyNumbers); //this won't
		sp.wonderfulAddNumber(big.begin(), big.end()); //test for member function to add multiple numbers in a single call
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	} */
	
	return 0;
}