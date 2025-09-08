/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:41:22 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/08 21:22:03 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {
	private:
		std::string _type;

	public:
		//parameterized constructor
		Weapon(std::string type) : _type(type) {};

		//destructor
		~Weapon() {};

		const std::string &getType() 
		{
			return _type;
		};

		void setType(std::string type)
		{
			this->_type = type;
		};
};

#endif