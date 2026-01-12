/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:29:53 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/12 18:05:11 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <stdint.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();          
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

	static bool parseLiteral(std::string literal);
	static std::string charToString(char c);
	static std::string intToString(int i);
	static std::string floatToString(float f);
	static std::string doubleToString(double d);
	static void printConversion(const std::string &charVal,
								const std::string &intVal,
								const std::string &floatVal,
								const std::string &doubleVal);

public:
	~ScalarConverter();
    static void convert(const std::string& literal);
};


#endif