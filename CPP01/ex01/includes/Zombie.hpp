/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:25:33 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/31 17:18:11 by scarlucc         ###   ########.fr       */
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
		std::string _name;

	public:
	//standard constructor	
	Zombie();

	//parameterized constructor
	Zombie(std::string name);
	
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

/*It must allocate N Zombie objects in a single allocation. Then, it must initialize the
zombies, giving each of them the name passed as a parameter. The function returns a
pointer to the first zombie.*/
Zombie* zombieHorde( int N, std::string name );

#endif