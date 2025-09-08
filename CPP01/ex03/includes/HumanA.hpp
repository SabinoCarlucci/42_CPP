/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:24:00 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/08 20:52:09 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;
		
	public:

		//parametrized constructor
		HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
		{
			//non serve scrivere niente?
		};
	
		void attack()
		{
			std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
		};
		
};