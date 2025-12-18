/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/17 17:15:04 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try 
	{
		Form f1;
		std::cout << std::endl;
		
		Form f2("pen request");
		std::cout << std::endl;
		
		Form f3("toilet paper request", 100);
		std::cout << std::endl;

		Form f6("Boss request", 1, 100);
		std::cout << std::endl;

		Bureaucrat boss("Boss", 1);
		boss.signForm(f6);
		std::cout << std::endl;

		//COPY FORM
		Form copia(f6);
		std::cout << std::endl;

		//TEST FIRMA
		Bureaucrat b1("Mario", 100);
		b1.signForm(f3);

		//TEST FIRMA CON ERRORE
		//b1.signForm(f6);
		
		//TEST COSTRUTTORE CON ERRORE (messaggio in fondo ad output)
		//Form f0("form sbagliato", 0);
		//Form f00("merdaccia", 151);
		//Form f5("boh", -100);
		
		std::cout << "non esegue se viene lanciata eccezione" << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Mistakes were made: " << e.what() << std::endl;
	}	
	return (0);
}