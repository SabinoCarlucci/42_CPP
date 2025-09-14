/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 18:24:00 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/14 17:56:18 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon &weapon;
		
	public:

		//parametrized constructor
		HumanA(std::string name, Weapon &weapon);
	
		void attack();
		
};

#endif