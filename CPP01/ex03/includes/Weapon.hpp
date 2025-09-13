/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:41:22 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/13 18:02:30 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {
	private:
		std::string type;

	public:
		//parameterized constructor
		Weapon(std::string type) : type(type) {};

		//destructor
		~Weapon() {};

		const std::string &getType() 
		{
			return type;
		};

		void setType(std::string type)
		{
			this->type = type;
		};
};

#endif