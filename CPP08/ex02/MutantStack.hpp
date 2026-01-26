/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:00:30 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/26 18:17:23 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
	//canonical form
	MutantStack() {}
	~MutantStack() {}
	MutantStack(const MutantStack& other) {}
	MutantStack &operator=(const MutantStack &other)
	
		
};

#endif