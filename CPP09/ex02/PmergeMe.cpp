/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:20:04 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/16 19:07:13 by scarlucc         ###   ########.fr       */
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
	
	//debug print
	/* std::cout << std::endl << "_vect: ";
	for (size_t it = 0; it < _vec.size(); it++)
	{
		std::cout << _vec[it] << " ";
	}
	std::cout << std::endl; */
	
	int group_size = 1;
	recursion(group_size);
}

void PmergeMe::printElements(int group_size, std::vector<int> vector_to_print)//modifica per usarlo su qualunque vettore
{
	std::vector<int>::iterator it_vec = vector_to_print.begin();
	while (it_vec != vector_to_print.end())
	{
		std::cout << "[ ";
		if (std::distance(it_vec, vector_to_print.end()) >= group_size)
		{
			for (int repeat = 0; repeat < group_size; repeat++)
			{
				std::cout << *it_vec << " ";//forse cambiare contenuto di questo ciclo
				it_vec++;
			}
		}
		else
		{
			while (it_vec != vector_to_print.end())
			{
				std::cout << *it_vec << " ";
				it_vec++;
			}			
		}
		std::cout << "] " << std::endl;	
	}
	std::cout << std::endl;
}

void PmergeMe::makeElements(int group_size)
{
	std::vector<int>::iterator it = _vec.begin();
	while (it != _vec.end())
	{
		if (std::distance(it, _vec.end()) >= group_size)
		{
			if (group_size > 1 && *(it + (group_size / 2) - 1) > *(it + group_size - 1))
				std::swap_ranges(it, it + group_size / 2, it + group_size / 2);
			it = it + group_size;
		}
		else
		{
			while (it != _vec.end())
				it++;		
		}
	}
	printElements(group_size, _vec);
}

void PmergeMe::makeMainPend(int group_size)
{
	std::vector<int>::iterator it = _vec.begin();
	size_t skip = group_size * 2;
	_vecPend.clear();//forse pulire _vecPend

	
	long remaining = std::distance(it, _vec.end());
		
	if(remaining >= (long)(skip))//salta i primi 2 elementi e prendi il terzo
	{
		_vecPend.insert(_vecPend.end(), it + skip, it + skip + group_size);
		it += skip + group_size;
	}

	while (it != _vec.end())
	{
		remaining = std::distance(it, _vec.end());
		
		if(remaining >= (long)(skip))//prendi un elemento ogni 2, se ci sono
		{
			_vecPend.insert(_vecPend.end(), it + group_size, it + skip);
			it += skip;
		}
		else if (remaining >= (long)group_size)//prendi elemento dispari, se c'e'
		{
			_vecPend.insert(_vecPend.end(), it, it + group_size);
			break;
		}
		else
			break;
	}

	//cancella numeri copiati
	it = _vec.begin();
	remaining = std::distance(it, _vec.end());
		
	if(remaining >= (long)(skip))//salta i primi 2 elementi e prendi il terzo
	{
		_vec.erase(it + skip, it + skip + group_size);
		it += skip;
	}
	
	while (it != _vec.end())
	{
		remaining = std::distance(it, _vec.end());
		
		if(remaining >= (long)(skip))//prendi un elemento ogni 2, se ci sono
		{
			_vec.erase(it + group_size, it + skip);
			it += group_size;
		}
		else if (remaining >= (long)group_size)//prendi elemento dispari, se c'e'
		{
			_vec.erase(it, it + group_size);
			break;
		}
		else
			break;
	}

	std::cout << "pend:" << std::endl;
	printElements(group_size, _vecPend);

	std::cout << "main:" << std::endl;;
	printElements(group_size, _vec);
}

//./PmergeMe 2 11 0 17 6 15 8 16 3 10 1 21 9 18 14 19 5 12 4 20 7 13
void PmergeMe::recursion(int group_size)
{
	makeElements(group_size);
	group_size *= 2;
	if (std::distance(_vec.begin(), _vec.end()) > group_size)
		recursion(group_size);
	
	//step 2 (main e pend)
	if (std::distance(_vec.begin(), _vec.end()) / group_size > 2)//if there are 2 groups and odd numbers, no insertion
	{
		printElements(group_size, _vec);
		makeMainPend(group_size);
		
		//implementing step 3
		binaryJacobsthalInsert(group_size);
	}
	/* cerca
	Step 3 can be pretty confusing.
	*/
}

void PmergeMe::binaryJacobsthalInsert(int group_size)
{
	int pend_blocks = _vecPend.size() / group_size;//8 / 4 = 2
	/* std::vector<int> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while (jacob.size() < pend_blocks)
	{
		int newJ = *(jacob.end() - 1) + *(jacob.end() - 2) * 2;
		jacob.push_back(newJ);
	}
		 */
	

	int previousJ = 1;
	int currentJ = 3;
	
	std::vector<int>::iterator itPend;
	std::vector<int>::iterator itMain = _vec.begin();
	
	for (int cont = 1; cont < currentJ - previousJ; cont++)
	{
		for (int loopJ = currentJ; loopJ > previousJ; loopJ--)
		{
				std::cout << "loopJ: " << loopJ << std::endl;
			if (pend_blocks >= currentJ - 1)//se ci sono abbastanza elementi in pend
				itPend = _vecPend.begin() + group_size * (loopJ - 1) - 1;//point to element's last number
			else
				itPend = _vecPend.end() - 1;				

			int insertionIndex = findInsertPosition(itPend, group_size);
				std::cout << "itPend: " << *itPend << std::endl;
			_vec.insert(_vec.begin() + insertionIndex * group_size, itPend - (group_size - 1), itPend + 1);

				std::cout << "dopo inserimento" << std::endl;
				std::cout << "pend:" << std::endl;
				printElements(group_size, _vecPend);

				std::cout << "main:" << std::endl;;
				printElements(group_size, _vec);
		}
		
		//ricalcola jacob
		int tmpJ = currentJ;
		currentJ = currentJ + previousJ * 2;
		previousJ = tmpJ;
	}
}

int PmergeMe::findInsertPosition(
    std::vector<int>::iterator itPend,
    int group_size)
{
    int left = 0;
    int right = ((_vec.size() / group_size) % 2 == 0) ? 
				(_vec.size() / group_size) / 2 :
				(_vec.size() / group_size) / 2 + 1;
	std::cout << "right = " << right << std::endl;

    while (left < right)
    {
        int mid = (left + right) / 2;

        int main_value =
            _vec[mid * group_size + group_size - 1];
		std::cout << "main_value: " << main_value << std::endl;

        if (*itPend < main_value)
            right = mid;
        else
            left = mid + 1;
    }
	//std::cout << "insertion index: " << left << std::endl;
    return left;
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