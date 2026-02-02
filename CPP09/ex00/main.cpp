/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:39:22 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/02 17:25:22 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	//(void)argv;//poi togli
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return (1);
	}
	//mettere try
	BitcoinExchange bitcoinexchange;//cambiare costruttore con argomento

	bitcoinexchange.processInput(argv[1]);
	return (0);
}