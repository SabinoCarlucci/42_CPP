/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:05:54 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/10 11:06:48 by scarlucc         ###   ########.fr       */
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
	
	public:
		std::string			getTarget() const;
		RobotomyRequestForm();
		RobotomyRequestForm(std::string		target);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
		void		doTheThing() const;
};

std::ostream& 		operator<<(std::ostream& os, const AForm& form);

#endif