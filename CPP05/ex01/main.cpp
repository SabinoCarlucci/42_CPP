/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:27 by scarlucc          #+#    #+#             */
/*   Updated: 2025/10/14 12:04:10 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try 
	{
		//Form f0("MEGADIRETTORE", 0);
		Form f1;
		
		Form f2("pen request");
		//TEST INCREMENTO/DECREMENTO
		//b2.incrementGrade();
		std::cout << f2 << std::endl;
		
		Form f3("toilet paper request", 100);
		//TEST INCREMENTO/DECREMENTO
		//b3.decrementGrade();
		//std::cout << b3 << std::endl;
		
		//Form b4("merdaccia", 151);
		//Form b5("boh", -100);
		Form f6("Boss", 1, 100);

		Form copia(f6);
		std::cout << copia << std::endl;

		//TEST FIRMA
		Bureaucrat b1("Mario", 100);
		b1.signForm(f3);
		
	}
	catch (std::exception & e)
	{
		std::cout << "Mistakes were made: " << e.what() << std::endl;
	}	
	return (0);
}