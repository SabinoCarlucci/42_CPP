/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:23:45 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/13 18:01:47 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("") 
{
	std::cout << "a nameless zombie rises" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead(er)!" << std::endl;
}

void Zombie::setName(std::string name)
{
	if (name.empty())
		name = "NPC";
	this->name = name;
	std::cout << "a previously nameless zombie has been named " << this->name << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}