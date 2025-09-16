/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:32:18 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 19:17:07 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
	
	public:
		ScavTrap();
		ScavTrap(std::string startName);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		void attack(const std::string& target);
		void guardGate();
};

#endif