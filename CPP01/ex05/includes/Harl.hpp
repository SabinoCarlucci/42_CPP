/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:54:13 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/13 16:56:52 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>

#ifndef HARL_HPP
#define HARL_HPP

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		void complain( std::string level );
};

#endif