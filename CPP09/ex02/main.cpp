/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:20:22 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/08 12:34:08 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Correct usage: " << argv[0] << " <2 or more positive integers>" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe sorter(argc - 1, argv + 1); //skip program name
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}