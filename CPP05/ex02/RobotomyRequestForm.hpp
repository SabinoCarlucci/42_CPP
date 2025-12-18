/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:05:54 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/16 11:01:36 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
		std::string		target;
		void		doTheThing() const;
	
	public:
		std::string			getTarget() const;
		RobotomyRequestForm();
		RobotomyRequestForm(std::string		target);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
		RobotomyRequestForm(RobotomyRequestForm const &other);
};

std::ostream& 		operator<<(std::ostream& os, const AForm& form);

#endif