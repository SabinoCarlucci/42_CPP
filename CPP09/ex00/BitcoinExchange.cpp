/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:23:42 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/02 18:45:41 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"
#include <stdlib.h> //for strtod
#include <fstream> //file stream, for reading files

BitcoinExchange::BitcoinExchange()
{
	std::ifstream db_csv("data.csv");//load database
	if (!db_csv.is_open())
	{
		std::cerr << "Error: could not open database." << std::endl;
		return;
	}

	std::string line;
	std::getline(db_csv, line); //skip database header
	
	while (std::getline(db_csv, line))
	{
		//std::cout << "line: " << line << std::endl;
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue; //just in case
		
		std::string date = line.substr(0, comma);
		double price = std::strtod(line.substr(comma + 1).c_str(), NULL);

		_db[date] = price;
	}
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());//load file
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	//che succede se file vuoto?
	std::string line;
	std::getline(file, line); //skip file header

	std::string date;
	std::string day;
	std::string month;
	std::string year;
	std::string value;

	while (std::getline(file, line))
	{
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		//check date
		date = line.substr(0, pipe - 1);
		value = line.substr(pipe + 2);
		
		size_t hyphen = date.find('-');
		year = date.substr(0, hyphen);

		size_t hyphenMonth = date.find('-', hyphen);
		month = date.substr(hyphen + 1, hyphenMonth - 2);
		
		day = date.substr(hyphenMonth + 1, pipe - 2);
		
		std::cout << day << std::endl;

		
		//check value
	}
	
}