/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:48:46 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/24 19:18:52 by scarlucc         ###   ########.fr       */
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
		void wonderfulAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
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