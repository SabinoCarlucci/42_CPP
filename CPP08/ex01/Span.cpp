/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:49:51 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/30 12:41:14 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N), _numbers(0)
{
	
}

Span::Span(const Span &span) : _maxSize(span._maxSize), _numbers(span._numbers)
{
	
}

Span::~Span()
{
	
}

Span &Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->_maxSize = span._maxSize;
	}
	return *this;
}

void Span::addNumber(int intToAdd)
{
	if (this->_numbers.size() >= this->_maxSize)
		throw Span::ContainerAlreadyFullException();

	this->_numbers.push_back(intToAdd);
}


unsigned int Span::shortestSpan()
{
	if (this->_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> workCopy(this->_numbers);
	std::sort(workCopy.begin(), workCopy.end());

	unsigned int span = workCopy[1] - workCopy[0];
	unsigned int workSpan;
	
	for (unsigned int i = 0; i < (workCopy.size() - 1); i++)
	{
		workSpan = workCopy[i + 1] - workCopy[i];
		if (workSpan < span)
			span = workSpan;
	}

	return span;
}

unsigned int Span::longestSpan()
{
	if (this->_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> workCopy(this->_numbers);
	std::sort(workCopy.begin(), workCopy.end());//.begin() e .end() sono iteratori

	return (workCopy.back() - workCopy.front());//.front() e .back() sono valori, riferimenti agli elementi
}


const char* Span::ContainerAlreadyFullException::what() const throw() { return "container is alredy full"; }

const char* Span::NotEnoughNumbersException::what() const throw() { return "Need at least 2 numbers for this"; }