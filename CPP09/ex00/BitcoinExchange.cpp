/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:23:42 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/04 14:18:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"
#include <stdlib.h> //for strtod
#include <fstream> //file stream, for reading files
#include <cctype> // isspace() for parsing
#include <sstream> //parsing month and day

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
	std::string year;
	size_t hyphen;//between year and month
	std::string month;
	int 		monthInt;
	size_t hyphenMonth;//between month and day
	std::string day;
	int			dayInt;
	std::string value;
	double amount; //converted value
	char *end; //first non converted char
	

	while (std::getline(file, line))
	{
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input (missing '|') => " << line << std::endl;
			continue;
		}
		if (pipe == 0 || !isspace(line[pipe - 1]) || !isspace(line[pipe + 1]))
		{
			std::cout << "Error: bad input (missing space around '|') => " << line << std::endl;
			continue;
		}
		
		//check date
		date = line.substr(0, pipe - 1);
		
		hyphen = date.find('-');
		if (hyphen == std::string::npos)
		{
			std::cout << "Error: bad input (missing '-') => " << line << std::endl;
			continue;
		}
		year = date.substr(0, hyphen);
		if (!is_numeric(year))
		{
			std::cout << "Error: bad input (year) => " << line << std::endl;
			continue;
		}

		hyphenMonth = date.find('-', hyphen + 1);
		if (hyphenMonth == std::string::npos)
		{
			std::cout << "Error: bad input (missing '-') => " << line << std::endl;
			continue;
		}
		month = date.substr(hyphen + 1, hyphenMonth - hyphen - 1);
		monthInt = std::atoi(month.c_str());
		if (!is_numeric(month) || monthInt < 1 || monthInt > 12)
		{
			std::cout << "Error: bad input (month) => " << line << std::endl;
			continue;
		}
		
		day = date.substr(hyphenMonth + 1, pipe - hyphenMonth - 1);
		dayInt = std::atoi(day.c_str());
		if (!is_numeric(day) || dayInt < 1 || dayInt > 31)
		{
			std::cout << "Error: bad input (day) => " << line << std::endl;
			continue;
		}

		
		//check value
		value = line.substr(pipe + 2);
		//char *end; //first non converted char
		amount = std::strtod(value.c_str(), &end);

		if (*end != '\0') //no spaces after value
		{
			std::cout << "Error: bad input (value) => " << line << std::endl;
			continue;
		}

		if (amount < 0)
		{
			std::cout << "Error: negative number => " << line << std::endl;
			continue;
		}

		if (amount > 1000)
		{
			std::cout << "Error: too large a number => " << line << std::endl;
			continue;
		}

		//std::cout << "value: " << value << " int value: " << amount << std::endl;//debugging, comment later
	}
}

bool BitcoinExchange::is_numeric(const std::string& s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!::isdigit(*it)) return false;
    }
    return !s.empty();
}