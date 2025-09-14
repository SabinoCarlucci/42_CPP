/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:20:47 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/14 17:39:50 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/HumanB.hpp"

//parametrized constructor
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {};

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
};

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " is giving you a mean look" << std::endl;
};