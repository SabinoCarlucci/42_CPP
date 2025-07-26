/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcsZombie.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:13:00 by scarlucc          #+#    #+#             */
/*   Updated: 2025/07/26 19:19:13 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SRCSZOMBIE_HPP
#define SRCSZOMBIE_HPP

#include "Zombie.hpp"

/* This function creates a zombie, names it, and returns it so you can use it outside
of the function scope. */
Zombie* newZombie( std::string name );

//This function creates a zombie, names it, and makes it announce itself.
void randomChump( std::string name );


#endif