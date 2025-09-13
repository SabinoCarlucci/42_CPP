/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:24:00 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/13 18:02:05 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon &weapon;
		
	public:

		//parametrized constructor
		HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
		{
			//non serve scrivere niente?
		};
	
		void attack()
		{
			std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
		};
		
};