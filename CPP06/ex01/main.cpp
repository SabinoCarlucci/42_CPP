/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:18:32 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/20 16:09:52 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

int main()
{
	std::cout << "TEST WITH POINTER " << std::endl;
	Data test;
	test.word = "hello";
	std::cout << "Data says: " << test.word << std::endl;
	Data* test_ptr = &test;
	std::cout << "pointer to data struct: " << test_ptr << std::endl;
	uintptr_t raw = Serializer::serialize(test_ptr);
	std::cout << "Serialized pointer's value: " << raw << std::endl;
	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer's value: " << deserialized << std::endl;
	test.word += " world";
	std::cout << "Data says: " << test.word << std::endl;
	std::cout << std::endl;


	std::cout << "TEST WITH NULL POINTER " << std::endl;
	Data* null_ptr = NULL;
	uintptr_t raw2 = Serializer::serialize(null_ptr);
	std::cout << "Serialized pointer's value: " << raw2 << std::endl;
	Data *deserialized2 = Serializer::deserialize(raw2);
	std::cout << "Deserialized pointer's value: " << deserialized2 << std::endl;
	std::cout << std::endl;
	

	std::cout << "TEST WITH DYNAMICALLY ALLOCATED POINTER " << std::endl;
	Data* dynamic_ptr = new Data;
	dynamic_ptr->word = "hello";
	std::cout << "Data says: " << dynamic_ptr->word << std::endl;
	std::cout << "pointer to dynamically allocated data struct: " << dynamic_ptr << std::endl;
	uintptr_t raw3 = Serializer::serialize(dynamic_ptr);
	std::cout << "Serialized pointer's value: " << raw3 << std::endl;
	Data *deserialized3 = Serializer::deserialize(raw3);
	std::cout << "Deserialized pointer's value: " << deserialized3 << std::endl;
	dynamic_ptr->word += " world";
	std::cout << "Data says: " << dynamic_ptr->word << std::endl;
	std::cout << std::endl;
	delete dynamic_ptr;
	
	return (0);
}