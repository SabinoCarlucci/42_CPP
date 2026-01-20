/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:46:20 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/20 15:18:24 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T* 				_data;
		unsigned int 	_size;

	public:
		//constructors
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		
		//destructor
		~Array();

		//assignment
		Array& operator=(const Array& other);

		//access
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;
};

#include "Array.tpp" //always after class

#endif