/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:39:22 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/04 17:39:07 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	//(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return (1);
	}

	BitcoinExchange bitcoinexchange(argv[1]);
	return (0);
}