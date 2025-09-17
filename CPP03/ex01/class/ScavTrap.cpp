/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:59:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 16:12:54 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include <iostream>

//default constructor
ScavTrap::ScavTrap() :ClapTrap("nameless")
{
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
	
	std::cout << "nameless ScavTrap has been created" << std::endl;
}

//parameterized constructor
ScavTrap::ScavTrap(std::string startName) : ClapTrap(startName)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;

    std::cout << "ScavTrap " << name << " has been created!" << std::endl;
}

//destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed!" << std::endl;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	this->setName(other.getName() + "_clone");
	std::cout << "(scav)" << other.getName() << " was copied to create " << this->getName() << std::endl;
}

//override assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Scav Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.getName();
		this->hitPoints = other.getHitPoints();
		this->energyPoints = other.getEnergyPoints();
		this->attackDamage = other.getAttackDamage();
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << "(scav)" << this->name << " cannot attack!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "(scav)" << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << "(scav)" << this->name << " cannot enter Gate keeper mode!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}