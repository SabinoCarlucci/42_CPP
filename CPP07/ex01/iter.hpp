/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:27:51 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/17 19:01:37 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

/* The first parameter is the address of an array 
	-> pointer ->  T* array
	
The second one is the length of the array, passed as a const value
	-> size_t const array_length 
	
The third one is a function that will be called on every element of the array
	*/

template <typename A, typename F> 
void iter(A* array, size_t const array_length, F func)
{
    for (size_t i = 0; i < array_length; i++)
		func(array[i]);
}

#endif