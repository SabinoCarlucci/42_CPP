/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:14:28 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 20:34:26 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap mario("Mario");
	ScavTrap luigi = mario;
	luigi.setName("Luigi");
	std::cout << std::endl;
	
	mario.attack("Luigi");
	luigi.takeDamage(mario.getAttackDamage());
	mario.attack("Luigi");
	luigi.takeDamage(mario.getAttackDamage());
	mario.attack("Luigi");
	luigi.takeDamage(mario.getAttackDamage());
	std::cout << std::endl;

	luigi.beRepaired(50);
	std::cout << std::endl;

	luigi.attack("Mario");
	mario.takeDamage(luigi.getAttackDamage());
	luigi.attack("Mario");
	mario.takeDamage(luigi.getAttackDamage());
	std::cout << std::endl;

	mario.guardGate();
	luigi.guardGate();
	std::cout << std::endl;

	luigi.attack("Mario");
	mario.takeDamage(luigi.getAttackDamage());
	luigi.attack("Mario");
	mario.takeDamage(luigi.getAttackDamage());
	luigi.attack("Mario");
	mario.takeDamage(luigi.getAttackDamage());
	luigi.attack("Mario");
	mario.takeDamage(luigi.getAttackDamage());
	std::cout << std::endl;

	return 0;
}