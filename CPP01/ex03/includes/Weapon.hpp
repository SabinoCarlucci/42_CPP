/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:41:22 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/14 17:58:17 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string type;

	public:
		//parameterized constructor
		Weapon(std::string type);

		//destructor
		~Weapon() {};

		const std::string &getType();

		void setType(std::string type);
};

#endif