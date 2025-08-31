/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:23:45 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/31 17:04:09 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie::Zombie()
{
	std::cout << "a nameless zombie rises" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << " is alive!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead(er)!" << std::endl;
}

void Zombie::setName(std::string name)
{
	if (name.empty())
		name = "NPC";
	this->_name = name;
	std::cout << "a previously nameless zombie has been named " << this->_name << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}