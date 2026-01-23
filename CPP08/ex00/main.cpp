/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:23:01 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/23 13:19:41 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <exception> //try and catch
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <deque>

int main(void)
{
	try
	{
		std::vector<int> vect;
		vect.push_back(1);
		vect.push_back(2);
		vect.push_back(42);

		easyfind(vect, 42);
		std::cout << "vect Value found :)" << std::endl;

		
		std::set<int> set;
		set.insert(1);
		set.insert(2);
		set.insert(33);

		easyfind(set, 2);
		std::cout << "set Value found :)" << std::endl;


		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(22);
		lst.push_back(33);

		easyfind(lst, 22);
		std::cout << "lst Value found :)" << std::endl;


		std::deque<int> dq;
		dq.push_back(11);
		dq.push_back(22);
		dq.push_back(33);

		easyfind(dq, 11);
		std::cout << "dq Value found :)" << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Value not found :(" << '\n';
	}
	
}