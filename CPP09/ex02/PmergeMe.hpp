/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:19:19 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/15 16:30:33 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iterator> //std::distance() to check if next group can be formed
#include <vector>
#include <deque>
#include <algorithm> //for swap_ranges()
#include <sys/time.h> //gettimeofday()
#include <string>
#include <iostream>
#include <sstream>


class PmergeMe //aggiungi standard orthodox
{
	private:
		std::vector<int> _vec;
		std::vector<int> _vecPend;
		std::deque<int> _deq;
		void parseInput(char **argv);
		void printBefore(char **argv);
		void printTime(struct timeval start, struct timeval end, size_t n_elements, std::string container);
		void sortVector(int argc, char **argv);
		void recursion(int group_size);
		void printElements(int group_size, std::vector<int> vector_to_print);
		void makeElements(int group_size);
		void makeMainPend(int group_size);
		void binaryJacobsthalInsert(int group_size);
		
	public:
		PmergeMe(int argc, char **argv);

	
	class NotPositiveIntegerException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NonNumericalValueException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class EmptyException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	
};

#endif