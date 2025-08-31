/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:23:23 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/31 15:36:09 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/srcsZombie.hpp"

int main(void)
{
	Zombie* mario = newZombie(BOLD_RED + "Mario" + RESET);
	Zombie* luigi = newZombie(BOLD_GREEN + "Luigi" + RESET);
	Zombie* peach = newZombie(BOLD_MAGENTA + "Peach" + RESET);
	
	randomChump(BOLD_CYAN + "Pippo" + RESET);
	randomChump(BOLD_YELLOW + "Pluto" + RESET);
	randomChump(BOLD_BLUE + "Paperino" + RESET);

	mario->announce();
	luigi->announce();
	peach->announce();

	delete mario;
	delete luigi;
	delete peach;
	
	return (0);
}