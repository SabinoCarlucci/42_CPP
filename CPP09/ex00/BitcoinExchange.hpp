/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:24:02 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/03 16:40:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;

	public:
		BitcoinExchange();

		void processInput(const std::string &filename);
		bool is_numeric(const std::string& s);
};

#endif