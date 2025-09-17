/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:29:32 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 20:30:43 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain& operator=(const Brain& other);
	
		std::string getIdea(int index) const;
		void setIdea(int index, const std::string& idea);
};

#endif