/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:20:22 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/06 19:04:20 by scarlucc         ###   ########.fr       */
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
		PmergeMe sorter(argv + 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}