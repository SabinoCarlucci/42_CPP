/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:25:33 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/13 18:01:47 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

const std::string	RESET			= "\033[0m";
const std::string	BOLD_RED		= "\033[1;31m";
const std::string	BOLD_GREEN		= "\033[1;32m";
const std::string	BOLD_YELLOW		= "\033[1;33m";
const std::string	BOLD_BLUE		= "\033[1;34m";
const std::string	BOLD_MAGENTA	= "\033[1;35m";
const std::string	BOLD_CYAN		= "\033[1;36m";
const std::string	BOLD_WHITE		= "\033[1;37m";

class Zombie {
	private:
		std::string name;

	public:
	//standard constructor	
	Zombie();
	
	//standard destructor
	~Zombie();

	void setName(std::string name);

	void announce( void );
};

/* This function creates a zombie, names it, and returns it so you can use it outside
of the function scope. */
Zombie* newZombie( std::string name );

//This function creates a zombie, names it, and makes it announce itself.
void randomChump( std::string name );

#endif