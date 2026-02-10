/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:20:04 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/10 18:09:54 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

PmergeMe::PmergeMe(int argc, char **argv)
{
	parseInput(argv);
	printBefore(argv);

	// ===== VECTOR =====
	struct timeval start_vec, end_vec;
	//std::vector<int> mergeVector;
	gettimeofday(&start_vec, NULL);//start timer

	//std::cout << "ciaone" << std::endl;
	sortVector(argc, argv);

	gettimeofday(&end_vec, NULL);//stop timer

	printTime(start_vec, end_vec, _vec.size(), "std::vector");

	/* // ===== DEQUE =====
	struct timeval start_deq, end_deq;
	gettimeofday(&start_deq, NULL);

	fillDeque(argv);
	sortDeque();

	gettimeofday(&end_deq, NULL);

	printDequeTime(start_deq, end_deq); */
}

void PmergeMe::parseInput(char **argv) //aggiungi controllo per duplicati
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

		if (value < 0 || value > INT_MAX)
			throw NotPositiveIntegerException();
	}
}

void PmergeMe::sortVector(int argc, char **argv)
{
	long temp;
	//char *endPointer;
	
	for (int it = 0; it < argc; it++) //from main passing argv + 1
	{
		temp = std::strtol(argv[it], NULL, 10);
		_vec.push_back(temp);
	}
	
	//stampa per debug, cancella dopo
	std::cout << std::endl;
	std::cout << "_vect: ";
	for (size_t it = 0; it < _vec.size(); it++)
	{
		std::cout << _vec[it] << " ";
	}
	std::cout << std::endl;

	//funzione ricorsiva qui con stampa di coppie tra [] es: [3 2] [56 123] ... 11
	int group_size = 1;
	recursion(group_size);

	
}

//./PmergeMe 2 11 0 17 6 15 8 16 3 10 1 21 9 18 14 19 5 12 4 20 7 13
void PmergeMe::recursion(int group_size)
{	
	std::vector<int>::iterator it = _vec.begin();
	while (it != _vec.end())
	{
		std::cout << "[ ";
		if (std::distance(it, _vec.end()) >= group_size) //>= invece di >
		{
			if (group_size > 1 && *(it + (group_size / 2) - 1) > *(it + group_size - 1))
				std::swap_ranges(it, it + group_size / 2, it + group_size / 2);
			for (int repeat = 0; repeat < group_size; repeat++)
			{
				std::cout << *it << " ";//forse cambiare contenuto di questo ciclo
				it++;
			}
		}
		else
		{
			while (it != _vec.end())
			{
				std::cout << *it << " ";
				it++;
			}			
		}
		std::cout << "] " << std::endl;	
	}
	std::cout << std::endl;
	group_size *= 2;
	if (std::distance(_vec.begin(), _vec.end()) > group_size)
		recursion(group_size);
	
	//main e pend e resto di cose
	/* cerca
	Step 3 can be pretty confusing.
	
	*/
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