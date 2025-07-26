/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:23:45 by scarlucc          #+#    #+#             */
/*   Updated: 2025/07/26 19:07:38 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Zombie.hpp"
#include <iostream>

void Zombie::announce( void )
{
	std::cout << this->name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}