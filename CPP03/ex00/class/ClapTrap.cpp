/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:32:08 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 15:48:01 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()  :name("nameless"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "nameless ClapTrap has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string startName) :name(startName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	this->setName(other.getName() + "_clone");
	std::cout << other.getName() << " was copied to create " << this->getName() << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.getName();
		this->hitPoints = other.getHitPoints();
		this->energyPoints = other.getEnergyPoints();
		this->attackDamage = other.getAttackDamage();
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << this->name << " cannot attack!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << this->name << " is already dead!" << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << this->name << " takes " << amount << " points of damage! Current hit points: " << this->hitPoints << std::endl;
	if (this->hitPoints == 0)
		std::cout << this->name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout << this->name << " cannot be repaired!" << std::endl;
		return ;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << this->name << " recovers " << amount << " hit points! Current hit points: " << this->hitPoints << std::endl;
}

//getters
std::string ClapTrap::getName() const
{
	return this->name;
}

int ClapTrap::getHitPoints() const
{
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

//setters

void ClapTrap::setName(std::string newName)
{
	this->name = newName;
}

void ClapTrap::setHitPoints(int newHitPoints)
{
	this->hitPoints = newHitPoints;
}

void ClapTrap::setEnergyPoints(int newEnergyPoints)
{
	this->energyPoints = newEnergyPoints;
}

void ClapTrap::setAttackDamage(int newAttackDamage)
{
	this->attackDamage = newAttackDamage;
}
