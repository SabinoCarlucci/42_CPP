/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/11 18:32:26 by scarlucc         ###   ########.fr       */
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
	try 
	{
		Intern bob;

		AForm* pardon_Hitler = bob.makeForm("pardon request", "Hitler");
		AForm* robotomize_Hitler = bob.makeForm("robotomy request", "Hitler");
		AForm* shrubbery_Hitler = bob.makeForm("shrubbery request", "Hitler");
		
		AForm* wrong_Hitler = bob.makeForm("Hitler", "Hitler");
		std::cout << std::endl;

		std::cout << *pardon_Hitler << std::endl;
		std::cout << *robotomize_Hitler << std::endl;
		std::cout << *shrubbery_Hitler << std::endl;
		
		if (wrong_Hitler)
			std::cout << *wrong_Hitler << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Mistakes were made: " << e.what() << std::endl;
	}	
	return (0);
}