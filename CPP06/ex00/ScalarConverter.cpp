/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:37:34 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/21 20:53:41 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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



void ScalarConverter::convert(const std::string& literal)
{
    //fa cose
    
    std::cout << "char: " << std::endl;
    std::cout << "int: " << std::endl;
    std::cout << "float: " << std::endl;
    std::cout << "double: " << std::endl;



}