/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:22:58 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/14 17:42:08 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/HumanA.hpp"

//parametrized constructor
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {};

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
};