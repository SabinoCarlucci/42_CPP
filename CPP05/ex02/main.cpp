/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/09 19:05:34 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try 
	{
		PresidentialPardonForm f1;
		std::cout << std::endl;
		
		//COPY FORM
		PresidentialPardonForm copia(f1);
		std::cout << std::endl;

		Bureaucrat boss("Boss", 1);
		boss.signForm(f1);
		std::cout << std::endl;

		//TEST FIRMA con errore
		Bureaucrat b1("Mario", 100);
		b1.signForm(copia);

		//TEST COSTRUTTORE CON ERRORE
		//Form f0("form sbagliato", 0);
		//Form f00("merdaccia", 151);
		//Form f5("boh", -100);
		
		//TEST FIRMA CON ERRORE
		/* boss.signForm(f1);;
		b1.signForm(f6); */
		
	}
	catch (std::exception & e)
	{
		std::cout << "Mistakes were made: " << e.what() << std::endl;
	}	
	return (0);
}