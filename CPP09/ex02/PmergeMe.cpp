/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:20:04 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/07 19:03:02 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

PmergeMe::PmergeMe(char **argv)
{
	parseInput(argv);
	printBefore(argv);

	// ===== VECTOR =====
	struct timeval start_vec, end_vec;
	std::vector<int> mergeVector;
	gettimeofday(&start_vec, NULL);//start timer

	//std::cout << "ciaone" << std::endl;
	sortVector(argv, mergeVector);

	gettimeofday(&end_vec, NULL);//stop timer

	printTime(start_vec, end_vec, mergeVector.size(), "std::vector");

	/* // ===== DEQUE =====
	struct timeval start_deq, end_deq;
	gettimeofday(&start_deq, NULL);

	fillDeque(argv);
	sortDeque();

	gettimeofday(&end_deq, NULL);

	printDequeTime(start_deq, end_deq); */
}

void PmergeMe::parseInput(char **argv)
{
	for (int i = 0; argv[i]; ++i)
	{
		std::string s(argv[i]);

		if (s.empty())
			throw EmptyException();

		for (size_t j = 0; j < s.size(); ++j)
		{
			if (!isdigit(s[j]))
				throw NonNumericalValueException();
		}

		long value = std::strtol(s.c_str(), NULL, 10);

		if (value <= 0 || value > INT_MAX)
			throw NotPositiveIntegerException();
	}
}

void PmergeMe::sortVector(char **argv, std::vector<int> mergeVector)
{
	while ()
	{
		//aggiungi numeri a vector
	}
}

void PmergeMe::printBefore(char **argv)
{
	std::cout << "Before: ";
	for (size_t i = 0; argv[i]; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printTime(struct timeval start, struct timeval end, size_t n_elements, std::string container)
{
	double time_elapsed = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec);
	
	std::cout << "Time to process a range of "
			  << n_elements
			  << " elements with "
			  << container
			  << " : " 
			  << time_elapsed
			  << " us" 
			  << std::endl;
}

const char *PmergeMe::NotPositiveIntegerException::what() const throw()
{
	return "Error: not a positive integer";
}

const char *PmergeMe::NonNumericalValueException::what() const throw()
{
	return "Error: not numeric char";
}

const char *PmergeMe::EmptyException::what() const throw()
{
	return "Error: empty value";
}