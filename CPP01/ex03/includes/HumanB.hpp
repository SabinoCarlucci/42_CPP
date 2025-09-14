/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:58:34 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/14 17:56:56 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;

	public:
		//parametrized constructor
		HumanB(std::string name);

		void setWeapon(Weapon &weapon);
	
		void attack();
};

#endif