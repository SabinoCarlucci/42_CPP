/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:37:34 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/14 19:18:24 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>

//ortodox canonical form
ScalarConverter::ScalarConverter()
{
	std::cout << "Created ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Terminated ScalarConverter" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}
//ortodox canonical form



//==============================================================

std::string ScalarConverter::charToString(char c)
{
	if (c >= 32 && c < 127)
		return std::string("'") + c + "'";
	return "Non displayable";
}

std::string ScalarConverter::intToString(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

std::string ScalarConverter::floatToString(float f)
{
	std::stringstream ss;
	ss << f << "f";
	return ss.str();
}

std::string ScalarConverter::doubleToString(double d)
{
	std::stringstream ss;
	ss << d;
	return ss.str();
}

//====================================================

void ScalarConverter::printConversion(const std::string &charVal,
								const std::string &intVal,
								const std::string &floatVal,
								const std::string &doubleVal)
{    
    std::cout << "char: " << charVal << std::endl;
    std::cout << "int: " << intVal << std::endl;
    std::cout << "float: " << floatVal << std::endl;
    std::cout << "double: " << doubleVal << std::endl;
}

//====================================================

bool ScalarConverter::parseLiteral(std::string literal)
{
	bool foundPoint = false;
	
	//empty literal
	if (literal.length() == 0)
	{
		std::cerr << "Empty literal" << std::endl;
		return false;
	}
		

	for (size_t counter = 0; counter < literal.length(); counter++)
	{
		if (counter == 0 && (literal[0] == '+' || literal[0] == '-'))
			continue;
		
		//literal has more than one . and/or there are no digits before/after .
		if (literal[counter] == '.')
		{
			if (!foundPoint && ((counter > 0 && isdigit(literal[counter - 1])) || ((counter + 1) < literal.length() && isdigit(literal[counter + 1]))))
			{
				foundPoint = true;
				continue;
			}
			else
			{
				std::cerr << "Invalid literal: Error with dots in literal" << std::endl;
				return false;
			}
		}
		
		//troppe f
		if (literal[counter] == 'f')
		{
			if (counter != (literal.length() - 1) || literal.length() == 1)
			{
				std::cerr << "Invalid literal: Error with 'f' in literal" << std::endl;
				return false;
			}
			continue;
		}

		//altre lettere o simboli
		if (!isdigit(literal[counter]))
		{
			std::cerr << "Invalid literal: non-digit characters" << std::endl;
			return (false);
		}
			
	}
	return true;//literal is ok
}

//====================================================

void ScalarConverter::convert(const std::string& literal)
{
	char 	printChar;
	int 	printInt;
	float 	printFloat;
	double 	printDouble;

	//altri controlli
	if (literal == "nan" || literal == "nanf")
	{
		printConversion(
			"impossible",
			"impossible",
			"nanf",
			"nan"
		);
		return;
	}

	if (literal == "+inf" || literal == "-inf")
	{
		printConversion(
			"impossible",
			"impossible",
			literal + "f",
			literal
		);
		return;
	}

	if (literal == "+inff" || literal == "-inff")
	{
		printConversion(
			"impossible",
			"impossible",
			literal,
			literal.substr(0, literal.size() - 1)
		);
		return;
	}
	
	//literal is char
	if ((literal.length() == 1 && !(literal[0] >= '0' && literal[0] <= '9'))
		|| (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && !(literal[1] >= '0' && literal[1] <= '9')))
	{
		
		char printThis;
		if (literal.length() == 1)
			printThis = literal[0];
		else
			printThis = literal[1];
		
		printChar = printThis;
		printInt = static_cast<int>(printChar);
		printFloat = static_cast<float>(printChar);
		printDouble = static_cast<double>(printChar);

		printConversion(
			charToString(printChar),
			intToString(printInt),
			floatToString(printFloat),
			doubleToString(printDouble)
		);
		return;//se e' char, non serve fare altro
	}

	//check if literal is valid
	if (!parseLiteral(literal))
		return;
	
	char* end;
	double value = std::strtod(literal.c_str(), &end);//input is converted in double first
	
	std::string stringChar;
	std::string stringInt;
	
	if (literal[literal.length() - 1] == 'f' && literal.length() > 1)
	{
		//e' un float
		printFloat = static_cast<float>(value);
		printDouble = static_cast<double>(printFloat);
		printInt = static_cast<int>(value);
		printChar = static_cast<char>(value);
	}
	else if (literal.find('.') != std::string::npos)
	{
		//e' un double

		printDouble = value;
		printFloat = static_cast<float>(value);
		printInt = static_cast<int>(value);
		printChar = static_cast<char>(value);
	}
	else
	{
		//e' un int
		if (value < std::numeric_limits<int>::min() ||
			value > std::numeric_limits<int>::max())
		{
			std::cerr << "given literal could not be represented as an integer" << std::endl;
			return;
		}
		else
		{
			printInt = static_cast<int>(value);
			printChar = static_cast<char>(printInt);
			printFloat = static_cast<float>(printInt);
			printDouble = static_cast<double>(printInt);
		}
	}


	//alla fine stampa tutto
	if (stringInt.empty())
		stringInt = intToString(printInt);
	if (stringChar.empty())
		stringChar = charToString(printChar);
		
	printConversion(
			stringChar,
			stringInt,
			floatToString(printFloat),
			doubleToString(printDouble)
	);
	return;
}