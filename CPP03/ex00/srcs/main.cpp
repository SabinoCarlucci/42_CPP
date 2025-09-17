/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:14:28 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 16:02:03 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap mario("Mario");
	ClapTrap luigi = mario;
	luigi.setName("Luigi");
	std::cout << std::endl;
	
	mario.attack("Luigi");
	luigi.takeDamage(mario.getAttackDamage());
	std::cout << std::endl;

	std::cout << "Setting Mario's attack damage to 3" << std::endl;
	mario.setAttackDamage(3);
	std::cout << std::endl;

	mario.attack("Luigi");
	luigi.takeDamage(mario.getAttackDamage());
	mario.attack("Luigi");
	luigi.takeDamage(mario.getAttackDamage());
	std::cout << std::endl;

	luigi.beRepaired(5);
	std::cout << std::endl;

	luigi.setAttackDamage(10);
	std::cout << "Setting Luigi's attack damage to 10" << std::endl;
	luigi.attack("Mario");
	mario.takeDamage(luigi.getAttackDamage());
	mario.attack("Luigi");
	mario.beRepaired(2);
	std::cout << std::endl;

	for (int i = 0; i < 9; i++)
		luigi.attack("Mario");
	//luigi wins. Brutality!

	return 0;
}