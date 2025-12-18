/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:35:36 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/16 11:01:49 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    private:
		std::string		target;
		void		doTheThing() const;
	
	public:
		std::string			getTarget() const;
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string		target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
		ShrubberyCreationForm(ShrubberyCreationForm const &other) ;
};

std::ostream& 		operator<<(std::ostream& os, const AForm& form);

#endif