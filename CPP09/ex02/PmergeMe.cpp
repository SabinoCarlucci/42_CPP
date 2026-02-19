/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:20:04 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/18 20:28:22 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

 
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

void PmergeMe::parseInput(char **argv)
{
	std::vector<int> check;
	
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
			
		if (check.size() > 0 && find(check.begin(), check.end(), (int)value) != check.end())
			throw DuplicateException();
		else
			check.insert(check.begin(), (int)value);
	}
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	int group_size = 1;
	parseInput(argv);

	// ===== VECTOR =====
	fillContainer(_vec, argc, argv);
	
	struct timeval start_vec, end_vec;
	gettimeofday(&start_vec, NULL);//start timer
	printBeforeAfter(_vec, "Before");
	
	recursionVec(group_size);

	gettimeofday(&end_vec, NULL);//stop timer
	printBeforeAfter(_vec, "After");
	printTime(start_vec, end_vec, _vec.size(), "std::vector");
	//printElements(1, _vec);//debug

	// ===== DEQUE =====
	fillContainer(_deq, argc, argv);
	
	struct timeval start_deq, end_deq;
	gettimeofday(&start_deq, NULL);

	recursionDeq(group_size);

	gettimeofday(&end_deq, NULL);
	printTime(start_deq, end_deq, _deq.size(), "std::deque");
}

void PmergeMe::makeElementsVec(int group_size)
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
	//printElements(group_size, _vec);//debug
}

void PmergeMe::makeMainPendVec(int group_size)
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

	/* std::cout << "pend:" << std::endl;
	printElements(group_size, _vecPend); */

	/* std::cout << "main:" << std::endl;;
	printElements(group_size, _vec); */
}

//./PmergeMe 2 11 0 17 6 15 8 16 3 10 1 21 9 18 14 19 5 12 4 20 7 13
void PmergeMe::recursionVec(int group_size)
{
	makeElementsVec(group_size);
	//group_size *= 2;
	if (std::distance(_vec.begin(), _vec.end()) > group_size)
		recursionVec(group_size * 2);		
	
	//step 2 (main e pend)
	if (std::distance(_vec.begin(), _vec.end()) / group_size > 2)//if there are 2 groups and odd numbers, no insertion
	{
		//printElements(group_size, _vec);
		makeMainPendVec(group_size);
		
		//implementing step 3
		binaryJacobsthalInsertVec(group_size);
	}
}

void PmergeMe::binaryJacobsthalInsertVec(int group_size)
{
    int pend_blocks = _vecPend.size() / group_size;
    if (pend_blocks == 0)
        return;

    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < pend_blocks)
    {
        int size = jacob.size();
        int newJ = jacob[size - 1] + 2 * jacob[size - 2];
        jacob.push_back(newJ);
    }

    int previous = 0;

    for (size_t j = 0; j < jacob.size(); j++)
    {
        int current = jacob[j];

        if (current > pend_blocks)
            current = pend_blocks;

        for (int block = current - 1; block >= previous; block--)
        {
            int start = block * group_size;
            int end   = start + group_size;

            int insertionIndex = findInsertPosition(start, group_size);

            _vec.insert(
                _vec.begin() + insertionIndex * group_size,
                _vecPend.begin() + start,
                _vecPend.begin() + end
            );
        }

        previous = current;

        if (previous >= pend_blocks)
            break;
    }
}

int PmergeMe::findInsertPosition(int start, int group_size)
{
    int pend_value = _vecPend[start + group_size - 1];

    int total_blocks = _vec.size() / group_size;

    int left = 0;
    int right = total_blocks;

    while (left < right)
    {
        int mid = (left + right) / 2;

        int main_value = _vec[mid * group_size + group_size - 1];

        if (pend_value < main_value)
            right = mid;
        else
            left = mid + 1;
    }
	//std::cout << "insertion index: " << left << std::endl;
    return left;
}



//======== DEQUE ==============

//./PmergeMe 2 11 0 17 6 15 8 16 3 10 1 21 9 18 14 19 5 12 4 20 7 13
void PmergeMe::recursionDeq(int group_size)
{
	makeElementsDeq(group_size);
	if (std::distance(_deq.begin(), _deq.end()) > group_size)
		recursionDeq(group_size * 2);		
	
	//step 2 (main e pend)
	if (std::distance(_deq.begin(), _deq.end()) / group_size > 2)//if there are 2 groups and odd numbers, no insertion
	{
		//printElements(group_size, _deq);
		makeMainPendDeq(group_size);
		
		//implementing step 3
		binaryJacobsthalInsertDeq(group_size);
	}
}

void PmergeMe::makeElementsDeq(int group_size)
{
	std::deque<int>::iterator it = _deq.begin();
	while (it != _deq.end())
	{
		if (std::distance(it, _deq.end()) >= group_size)
		{
			if (group_size > 1 && *(it + (group_size / 2) - 1) > *(it + group_size - 1))
				std::swap_ranges(it, it + group_size / 2, it + group_size / 2);
			it = it + group_size;
		}
		else
		{
			while (it != _deq.end())
				it++;		
		}
	}
	//printElements(group_size, _deq);//debug
}

void PmergeMe::makeMainPendDeq(int group_size)
{
	std::deque<int>::iterator it = _deq.begin();
	size_t skip = group_size * 2;
	_deqPend.clear();

	
	long remaining = std::distance(it, _deq.end());
		
	if(remaining >= (long)(skip))//salta i primi 2 elementi e prendi il terzo
	{
		_deqPend.insert(_deqPend.end(), it + skip, it + skip + group_size);
		it += skip + group_size;
	}

	while (it != _deq.end())
	{
		remaining = std::distance(it, _deq.end());
		
		if(remaining >= (long)(skip))//prendi un elemento ogni 2, se ci sono
		{
			_deqPend.insert(_deqPend.end(), it + group_size, it + skip);
			it += skip;
		}
		else if (remaining >= (long)group_size)//prendi elemento dispari, se c'e'
		{
			_deqPend.insert(_deqPend.end(), it, it + group_size);
			break;
		}
		else
			break;
	}

	//cancella numeri copiati
	it = _deq.begin();
	remaining = std::distance(it, _deq.end());
		
	if(remaining >= (long)(skip))//salta i primi 2 elementi e prendi il terzo
		it = _deq.erase(it + skip, it + skip + group_size);
	
	while (it != _deq.end())
	{
		remaining = std::distance(it, _deq.end());
		
		if(remaining >= (long)(skip))//prendi un elemento ogni 2, se ci sono
			it = _deq.erase(it + group_size, it + skip);
		else if (remaining >= (long)group_size)//prendi elemento dispari, se c'e'
		{
			it = _deq.erase(it, it + group_size);
			break;
		}
		else
			break;
	}

	//debug
	/* std::cout << "pend:" << std::endl;
	printElements(group_size, _deqPend);

	std::cout << "main:" << std::endl;;
	printElements(group_size, _deq); */
}

int PmergeMe::findInsertPositionDeq(int start, int group_size)
{
    int pend_value = _deqPend[start + group_size - 1];

    int total_blocks = _deq.size() / group_size;

    int left = 0;
    int right = total_blocks;

    while (left < right)
    {
        int mid = (left + right) / 2;

        int main_value = _deq[mid * group_size + group_size - 1];

        if (pend_value < main_value)
            right = mid;
        else
            left = mid + 1;
    }
	//std::cout << "insertion index: " << left << std::endl;
    return left;
}

void PmergeMe::binaryJacobsthalInsertDeq(int group_size)
{
    int pend_blocks = _deqPend.size() / group_size;
    if (pend_blocks == 0)
        return;

    std::deque<int> jacob;
    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < pend_blocks)
    {
        int size = jacob.size();
        int newJ = jacob[size - 1] + 2 * jacob[size - 2];
        jacob.push_back(newJ);
    }

    int previous = 0;

    for (size_t j = 0; j < jacob.size(); j++)
    {
        int current = jacob[j];

        if (current > pend_blocks)
            current = pend_blocks;

        for (int block = current - 1; block >= previous; block--)
        {
            int start = block * group_size;
            int end   = start + group_size;

            int insertionIndex = findInsertPositionDeq(start, group_size);

            _deq.insert(
                _deq.begin() + insertionIndex * group_size,
                _deqPend.begin() + start,
                _deqPend.begin() + end
            );
        }

        previous = current;

        if (previous >= pend_blocks)
            break;
    }
}



// ============ ERRORS ==============
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

const char *PmergeMe::DuplicateException::what() const throw()
{
	return "Error: duplicate value";
}

//=========

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{
	
}