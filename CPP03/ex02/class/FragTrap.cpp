/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:03:47 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/16 20:20:13 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include <iostream>

//default constructor
FragTrap::FragTrap()
{
	hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
	
	std::cout << "nameless FragTrap has been created" << std::endl;
}

//parameterized constructor
FragTrap::FragTrap(std::string startName) : ClapTrap(startName)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;

    std::cout << "FragTrap " << name << " has been created!" << std::endl;
}

//destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed!" << std::endl;
}

//copy constructor
FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	this->setName(other.getName() + "_clone");
	std::cout << "(Frag)" << other.getName() << " was copied to create " << this->getName() << std::endl;
}

//override assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Frag Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.getName();
		this->hitPoints = other.getHitPoints();
		this->energyPoints = other.getEnergyPoints();
		this->attackDamage = other.getAttackDamage();
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << "(Frag)" << this->name << " cannot attack!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "(Frag)" << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << "(Frag)" << this->name << " cannot high five!" << std::endl;
		return ;
	}
	std::cout << "(Frag)" << this->name << " is requesting a high five! ✋" << std::endl;
}
