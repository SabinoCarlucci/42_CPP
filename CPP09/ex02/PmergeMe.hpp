/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:19:19 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/08 18:38:31 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iterator> //std::distance() to check if next group can be formed
#include <vector>
#include <deque>
#include <sys/time.h> //gettimeofday()
#include <string>
#include <iostream>
#include <sstream>


class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		void parseInput(char **argv);
		void printBefore(char **argv);
		void printTime(struct timeval start, struct timeval end, size_t n_elements, std::string container);
		void sortVector(int argc, char **argv);
		void recursion(int increment);
		
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