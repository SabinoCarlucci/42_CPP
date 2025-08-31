/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:25:33 by scarlucc          #+#    #+#             */
/*   Updated: 2025/08/31 15:31:44 by scarlucc         ###   ########.fr       */
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
	
	//standard destructor
	~Zombie();

	void setName(std::string name);

	void announce( void );
};

#endif