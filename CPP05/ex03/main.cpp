/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/18 14:36:14 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm* pardon_Hitler = NULL;
	AForm* robotomize_Hitler = NULL;
	AForm* shrubbery_Hitler = NULL;
	
	AForm* wrong_Hitler = NULL;
		
	try 
	{
		Intern bob;

		pardon_Hitler = bob.makeForm("pardon request", "Hitler");
		robotomize_Hitler = bob.makeForm("robotomy request", "Hitler");
		shrubbery_Hitler = bob.makeForm("shrubbery request", "Hitler");
		
		//uncomment for error
		//wrong_Hitler = bob.makeForm("Hitler", "Hitler");
		std::cout << std::endl;

		std::cout << *pardon_Hitler << std::endl;
		std::cout << *robotomize_Hitler << std::endl;
		std::cout << *shrubbery_Hitler << std::endl;
		std::cout << std::endl;

		std::cout << "SIGN FORM" << std::endl;
		Bureaucrat boss("Boss", 1);
		boss.signForm(*shrubbery_Hitler);
		boss.executeForm(*shrubbery_Hitler);
		std::cout << std::endl;
		
		if (wrong_Hitler)
			std::cout << *wrong_Hitler << std::endl;		
	}
	catch (std::exception & e)
	{
		std::cout << "Mistakes were made: " << e.what() << std::endl;
	}

	delete pardon_Hitler;
	delete robotomize_Hitler;
	delete shrubbery_Hitler;
	if (wrong_Hitler)
		delete wrong_Hitler;
	return (0);
}