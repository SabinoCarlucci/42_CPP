/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:48:46 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/30 12:42:24 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
		
	public:
		Span(unsigned int N);
		Span(const Span &span);
		~Span();
		Span &operator=(const Span &span);
		
		void addNumber(int intToAdd);
		
		template <typename iter>
		void wonderfulAddNumber(iter begin, iter end)
		{
			size_t distance = std::distance(begin, end);

			if (_numbers.size() + distance > _maxSize)
				throw ContainerAlreadyFullException();

			//v.insert(pos, first, last);   // Insert range of elements 
			_numbers.insert(_numbers.end(), begin, end);
		}
		
		unsigned int shortestSpan();
		unsigned int longestSpan();

	//exception classes
	class ContainerAlreadyFullException : public std::exception {
		public:
			virtual const char* what() const throw();
			
	};

	class NotEnoughNumbersException : public std::exception {
		public:
			virtual const char* what() const throw();
			
	};
};

#endif