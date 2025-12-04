/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/04 19:04:15 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main(void)
{
	try 
	{
		Bureaucrat b1;
		std::cout << std::endl;
		
		Bureaucrat b2("ciccio");
		//TEST INCREMENTO/DECREMENTO
		b2.incrementGrade();
		std::cout << b2 << std::endl;
		std::cout << std::endl;
		
		Bureaucrat b3("mario", 100);
		//TEST INCREMENTO/DECREMENTO
		b3.decrementGrade();
		std::cout << b3 << std::endl;
		std::cout << std::endl;
		
		Bureaucrat b6("Boss", 1);
		std::cout << std::endl;

		//TEST COSTRUTTORE CON ERRORE
		//Bureaucrat b0("MEGADIRETTORE", 0);
		//Bureaucrat b4("merdaccia", 151);
		//Bureaucrat b5("boh", -100);
		
		//TEST INCREMENTO/DECREMENTO CON ERRORE
		//b6.incrementGrade();
		//b1.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Mistakes were made: " << e.what() << std::endl;
	}	
	return (0);
}