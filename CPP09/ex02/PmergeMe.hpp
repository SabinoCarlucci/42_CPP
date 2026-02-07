/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:19:19 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/07 17:48:13 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
		void sortVector(char **argv, std::vector<int> mergeVector);
		
	public:
		PmergeMe(char **argv);

	
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