/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:58:34 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/08 20:37:50 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;

	public:
	
		//parametrized constructor
		HumanB(std::string name) : _name(name), _weapon(NULL)
		{
			
		};

		void setWeapon(Weapon &weapon)
		{
			this->_weapon = &weapon;
		};
	
		void attack()
		{
			if (this->_weapon)
				std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
			else
				std::cout << this->_name << " is unarmed, just looking at you with an angry face" << std::endl;
		};
};