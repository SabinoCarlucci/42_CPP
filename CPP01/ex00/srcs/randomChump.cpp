/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:37:03 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/29 19:20:53 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/srcsZombie.hpp"

void randomChump( std::string name )
{
	Zombie stack;
	stack.setName(name);
	stack.announce();
}