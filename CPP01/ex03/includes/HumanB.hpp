/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:58:34 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/13 18:02:05 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;

	public:
	
		//parametrized constructor
		HumanB(std::string name) : name(name), weapon(NULL)
		{
			
		};

		void setWeapon(Weapon &weapon)
		{
			this->weapon = &weapon;
		};
	
		void attack()
		{
			if (this->weapon)
				std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
			else
				std::cout << this->name << " is unarmed, just looking at you with an angry face" << std::endl;
		};
};