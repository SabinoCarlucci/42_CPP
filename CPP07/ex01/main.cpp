/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:28:01 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/17 19:29:51 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "iter.hpp"
#include <iostream>


template <typename A>
void print(const A& a)
{
	std::cout << a << " ";
}

void increment(int &a)
{
	a++;
}

template <typename B>
void decrement(B &b)
{
	b--;
}

 int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "Original: ";
	iter(arr, 5, print<int>);
	std::cout << std::endl;

	iter(arr, 5, increment);

	std::cout << "Modified: ";
	iter(arr, 5, print<int>);
	std::cout << std::endl;

	
	char c_array[] = {'b', 'z', 'c'};
	iter(c_array, 3, print<char>);
	std::cout << std::endl;

	iter(c_array, 3, decrement<char>);

	iter(c_array, 3, print<char>);
	std::cout << std::endl;
	
	
	std::string str_array[] = {"hello", "world", "something"};
	iter(str_array, 3, print<std::string>);
	std::cout << std::endl;
	
	return (0);
}