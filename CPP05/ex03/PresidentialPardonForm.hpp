/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:48:09 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/16 09:39:17 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
    private:
		std::string		target;
		void			doTheThing() const;
	
	public:
		std::string			getTarget() const;
		PresidentialPardonForm();
		PresidentialPardonForm(std::string		target);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		PresidentialPardonForm(PresidentialPardonForm const &other);
};

std::ostream& 		operator<<(std::ostream& os, const AForm& form);

#endif