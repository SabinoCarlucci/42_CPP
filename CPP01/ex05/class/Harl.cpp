/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:54:03 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/13 17:37:17 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "../includes/Harl.hpp"

void Harl::debug( void )
{
	std::string message = "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
	std::cout << message << std::endl;
}

void Harl::info( void )
{
	std::string message = "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	std::cout << message << std::endl;
}

void Harl::warning( void )
{
	std::string message = "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
	std::cout << message << std::endl;
}

void Harl::error( void )
{
	std::string message = "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
	std::cout << message << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*functions[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[4] = { "debug", "info", "warning", "error" };
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "you have selected " << level << "\n	I don't know what that is." << std::endl;
}
