/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:17:36 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/20 14:50:18 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>
#include <iostream>


struct Data
{
	std::string word;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer& other);
		

	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif