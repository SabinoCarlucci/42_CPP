/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:15:39 by scarlucc          #+#    #+#             */
/*   Updated: 2025/07/19 19:14:54 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include	"../includes/PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	//ciclo infinito
	while (true)
	{
		std::cout << "Enter one of the following: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, line);
		//std::cout << line << std::endl;
		if (line.compare("TEST") == 0) {phonebook.testing();}
		else if (line.compare("ADD") == 0) {phonebook.add();}
		else if (line.compare("SEARCH") == 0) {phonebook.search();}
		else if (line.compare("EXIT") == 0) {break;}
	}
	return (0);
}
