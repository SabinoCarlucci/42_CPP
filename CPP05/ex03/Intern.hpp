/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:27:59 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/10 17:29:04 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef INTERN.HPP
#define INTERN.HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <map>

class Intern {
	public:
	
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern& Intern);
		AForm* makeForm(std::string formName, std::string target);
};

#endif