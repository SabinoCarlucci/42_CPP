/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:36:48 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/31 16:01:57 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* heap = new Zombie();
	heap->setName(name);
	
	return (heap);
}