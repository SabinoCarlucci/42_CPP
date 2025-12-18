/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:27:59 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/18 14:08:41 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef INTERN_HPP
#define INTERN_HPP

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

		class UnknownFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::map<std::string, AForm* (Intern::*)(std::string const &target)> forms;
		AForm* createShrubbery(const std::string &target);
   		AForm* createRobotomy(std::string const &target);
    	AForm* createPresidential(const std::string &target);
};

#endif