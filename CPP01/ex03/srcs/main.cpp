/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:28:30 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/14 18:02:32 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"
#include <iostream>

void test_subject()
{
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}

void test_unarmed_HumanB()
{
	std::cout << "TEST 1: HumanB attacks unarmed, gets a weapon, attacks again, gets void weapon, attacks again" << std::endl;
	HumanB Mario("Mario");
	Mario.attack();
	
	Weapon sword("sword");
	Mario.setWeapon(sword);
	Mario.attack();
	
	Weapon invisible_weapon("");
	Mario.setWeapon(invisible_weapon);
	Mario.attack();

	Weapon cartoon_weapon("::|===>");
	Mario.setWeapon(cartoon_weapon);
	Mario.attack();
	
	std::cout << std::endl;
}

void test_HumanA_HumanB_same_weapon()
{
	std::cout << "TEST 2: HumanA and HumanB get same weapon and attack" << std::endl;
	Weapon hammer("hammer");
	
	HumanB Mario("Mario");
	HumanA Luigi("Luigi", hammer);
	
	Mario.setWeapon(hammer);
	Mario.attack();
	Luigi.attack();
	std::cout << std::endl;
}

int main()
{
	test_unarmed_HumanB();
	test_HumanA_HumanB_same_weapon();
	test_subject();
	
	return 0;
}