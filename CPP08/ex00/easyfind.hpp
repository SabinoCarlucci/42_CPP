/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:57:03 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/23 13:04:31 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T& intContainer, int findThis)
{
	if (std::find(intContainer.begin(), intContainer.end(), findThis) == intContainer.end())
		throw std::exception();
}

#endif