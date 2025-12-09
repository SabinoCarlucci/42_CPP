/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:48:09 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/09 19:06:08 by scarlucc         ###   ########.fr       */
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
	
	public:
		std::string			getTarget() const;
		/* std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const; */
		PresidentialPardonForm();
		PresidentialPardonForm(std::string		target);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		void		doTheThing() const;
};

std::ostream& 		operator<<(std::ostream& os, const AForm& form);

#endif