/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:59:59 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/28 18:18:50 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack.top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "mstack.size: " << mstack.size() << std::endl;

	std::string emptyOrNot = (mstack.empty()) ? "empty" : "not empty";
	std::cout << "mstack is: " << emptyOrNot << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << std::endl;
	std::cout << "print all MutantStack:" << std::endl;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "end MutantStack:" << std::endl;
	std::cout << std::endl;
//=========================================

	std::cout << "reverse iterators:" << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << std::endl;
	
//=========================================

	const MutantStack<int> constMstack(mstack);
	std::cout << "constMstack.top: " << constMstack.top() << std::endl;

	MutantStack<int>::const_iterator Cit = constMstack.begin();
	MutantStack<int>::const_iterator Cite = constMstack.end();

	++Cit;
	--Cit;

	std::cout << std::endl;
	std::cout << "print all constMstack:" << std::endl;
	
	while (Cit != Cite)
	{
		std::cout << *Cit << std::endl;
		++Cit;
	}

	std::cout << "end constMstack:" << std::endl;
	std::cout << std::endl;
	
//=========================================
	
	std::stack<int> s(mstack); //crea std::stack copiando mstack, per dimostrare che sono compatibili

	// confronto con list
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "print all lst:" << std::endl;
	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
		std::cout << *lit << std::endl;
	std::cout << "end lst:" << std::endl;
	std::cout << std::endl;
	
	return 0;
}