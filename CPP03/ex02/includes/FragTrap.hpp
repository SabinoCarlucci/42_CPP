/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:03:38 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 20:12:50 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
	
	public:
		FragTrap();
		FragTrap(std::string startName);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif