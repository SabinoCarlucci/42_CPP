/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:41:00 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/14 17:33:27 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {};

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType() 
{
	return type;
}