/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:39:18 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/31 17:21:20 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Zombie.hpp"
#include <sstream>

std::string	intToString(int i)
{
	std::stringstream ss;
	ss << i;
	return (ss.str());
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	if (name.empty())
		name = "generic zombie";
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(intToString(i + 1) + "° " + name);
	
	return (horde);
}