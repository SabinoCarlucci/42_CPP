/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:48:17 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/20 15:30:03 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

//ortodox canonical form
Serializer::Serializer()
{
	std::cout << "Created Serializer" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Terminated Serializer" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}
//ortodox canonical form



/* Syntax
reinterpret_cast< target-type >( expression )		
Returns a value of type target-type. */

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}