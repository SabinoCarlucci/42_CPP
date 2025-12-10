/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/10 13:02:06 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try 
	{
		PresidentialPardonForm f1("Hitler");
		std::cout << std::endl;
		
		//COPY FORM
		PresidentialPardonForm copia(f1);
		std::cout << std::endl;

		Bureaucrat boss("Boss", 1);
		boss.signForm(f1);
		std::cout << std::endl;

		//TEST FIRMA con errore
		Bureaucrat b1("Mario", 100);
		//b1.signForm(copia); //uncomment to test error
		//b1.executeForm(copia); //uncomment to test error
		//b1.executeForm(f1); //uncomment to test error

		boss.executeForm(f1); //uncomment to test error

		//TEST ROBOTOMY
		std::cout << "TEST ROBOTOMY" << std::endl;
		RobotomyRequestForm robotomy("Frankenstein");
		std::cout << std::endl;

		RobotomyRequestForm copiaR(robotomy);
		std::cout << std::endl;

		Bureaucrat doctor("Doc", 72);
		doctor.signForm(robotomy);
		std::cout << std::endl;

		Bureaucrat surgeon("Surg", 45);
		surgeon.executeForm(robotomy);
		std::cout << std::endl;

		//error
		/* doctor.executeForm(copiaR);
		std::cout << std::endl; */

		//TEST SHRUBBERY
		std::cout << "TEST SHRUBBERY" << std::endl;

		ShrubberyCreationForm shrub("pine");
		std::cout << std::endl;

		ShrubberyCreationForm copiaS(shrub);
		std::cout << std::endl;

		Bureaucrat gardener("gard", 145);
		gardener.signForm(shrub);
		std::cout << std::endl;

		Bureaucrat gard2("gard2", 137);
		gard2.executeForm(shrub);
		std::cout << std::endl;

		//error
		/* doctor.executeForm(copiaR);
		std::cout << std::endl; */
	}
	catch (std::exception & e)
	{
		std::cout << "Mistakes were made: " << e.what() << std::endl;
	}	
	return (0);
}