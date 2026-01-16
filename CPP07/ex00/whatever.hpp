/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:27:35 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/16 17:24:31 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>


template <typename T> void swap(T& x, T& y)
{
    T z;
	
	z = x;
	x = y;
	y = z;
}

template <typename T> T min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T> T max(T x, T y)
{
    return (x > y) ? x : y;
}



#endif