/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:23:23 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/31 17:34:51 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Zombie.hpp"

int main(void)
{
	int zombieNumber = 3;
	
	Zombie* horde = zombieHorde(zombieNumber, "Gennaro");

	for (int i = 0; i < zombieNumber; i++)
		horde[i].announce();

	delete[] horde;
	
	return (0);
}