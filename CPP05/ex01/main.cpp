/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/10/13 11:26:00 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

int main(void)
{
	try 
	{
		//Form b0("MEGADIRETTORE", 0);
		Form b1;
		
		Form b2("pen request");
		//TEST INCREMENTO/DECREMENTO
		//b2.incrementGrade();
		std::cout << b2 << std::endl;
		
		Form b3("mario", 100);
		//TEST INCREMENTO/DECREMENTO
		//b3.decrementGrade();
		//std::cout << b3 << std::endl;
		
		//Form b4("merdaccia", 151);
		//Form b5("boh", -100);
		Form b6("Boss", 1, 100);

		Form copia(b6);
		std::cout << copia << std::endl;

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