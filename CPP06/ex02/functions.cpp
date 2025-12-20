/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:47:38 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/20 18:15:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "functions.hpp"
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()

Base * generate(void)
{
	// Get a different random number each time the program runs
  	srand(time(0));
  
  	// Generate a random number between 0 and 2
  	int randomNum = rand() % 3;
	
	if (randomNum == 0)
		return new A;
	else if (randomNum == 1)
		return new B;
	else if (randomNum == 2)
		return new C;
	else
		return NULL;
}

/* Syntax
dynamic_cast< target-type >( expression )		
 */

void identify(Base* p)
{
	if (dynamic_cast< A* >( p ))
		std::cout << "A" << std::endl;
	else if (dynamic_cast< B* >( p ))
		std::cout << "B" << std::endl;
	else if (dynamic_cast< C* >( p ))
		std::cout << "C" << std::endl;
	else
		std::cout << "neither of A, B or C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast< A& >( p );
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast< B& >( p );
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast< C& >( p );
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "something went wrong" << std::endl;
			}
		}
	}
}