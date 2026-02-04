/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:24:02 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/04 17:40:24 by scarlucc         ###   ########.fr       */
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
		
		void load_database();
		void processInput(const std::string &filename);
		bool is_numeric(const std::string& s);
		void convert(std::string line, std::string date, double amount);
		
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(BitcoinExchange other);
		~BitcoinExchange();
};

#endif