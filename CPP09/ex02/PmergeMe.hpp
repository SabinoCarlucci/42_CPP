/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:19:19 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/18 20:19:12 by scarlucc         ###   ########.fr       */
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
		std::deque<int> _deqPend;

		template <typename T>
		void printBeforeAfter(const T &container, std::string when)
		{
			std::cout << when << ": ";
			for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
			{
				std::cout << *it;
				
				//typename T::const_iterator nextIt = it;
				if (it != container.end())
					std::cout << " ";
			}
			std::cout << std::endl;
		}
		
		template <typename T>
		void fillContainer(T &container, int argc, char **argv)
		{
			long temp;
			for (int it = 0; it < argc; it++) //from main passing argv + 1
			{
				temp = std::strtol(argv[it], NULL, 10);
				container.push_back(temp);
			}
		}

		template <typename Container>
		void printElements(int group_size, const Container& container)
		{
			typename Container::const_iterator it = container.begin();

			while (it != container.end())
			{
				std::cout << "[ ";

				if (std::distance(it, container.end()) >= group_size)
				{
					for (int repeat = 0; repeat < group_size; repeat++)
					{
						std::cout << *it << " ";
						++it;
					}
				}
				else
				{
					while (it != container.end())
					{
						std::cout << *it << " ";
						++it;
					}
				}

				std::cout << "]" << std::endl;
			}

			std::cout << std::endl;
		}

		void parseInput(char **argv);
		void printTime(struct timeval start, struct timeval end, size_t n_elements, std::string container);
		
		//vector
		void recursionVec(int group_size);
		void printElements(int group_size, std::vector<int> vector_to_print);
		void makeElementsVec(int group_size);
		void makeMainPendVec(int group_size);
		void binaryJacobsthalInsertVec(int group_size);
		int findInsertPosition(int start, int group_size);

		//deque
		void recursionDeq(int group_size);
		void makeElementsDeq(int group_size);
		void makeMainPendDeq(int group_size);
		void binaryJacobsthalInsertDeq(int group_size);
		int findInsertPositionDeq(int start, int group_size);
		
	public:
		PmergeMe(int argc, char **argv);
		
		PmergeMe();
		PmergeMe &operator=(PmergeMe other);
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

	
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

	class DuplicateException : public std::exception
	{
	public:
		const char *what() const throw();
	};

};

#endif