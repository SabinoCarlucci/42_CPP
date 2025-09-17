/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:14:24 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 15:47:20 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	private:
		std::string name;
		int 		hitPoints;
		int 		energyPoints;
		int 		attackDamage;

	public:
		//canonical form
		ClapTrap();
		ClapTrap(std::string startName);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);

		//member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		//getters
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;

		//setters
		void setName(std::string newName);
		void setHitPoints(int newHitPoints);
		void setEnergyPoints(int newEnergyPoints);
		void setAttackDamage(int newAttackDamage);		
};


#endif