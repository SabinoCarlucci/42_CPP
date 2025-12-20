/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:46:49 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/20 18:17:38 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "functions.hpp"
#include "Base.hpp"

int main()
{
	Base* p = generate();
	Base* null_ptr = NULL;
	Base &ref = *p;
	
	std::cout << "pointer is: ";
	identify(p);

	std::cout << "pointer is: ";
	identify(null_ptr);

	std::cout << "reference is: ";
	identify(ref);
	
	delete p;

	return (0);
}