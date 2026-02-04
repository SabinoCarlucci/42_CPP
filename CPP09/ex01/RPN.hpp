/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:10:58 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/04 19:11:27 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class rpn
{
	private:
		//std::stack
	
	public:
		rpn();
		rpn(const rpn &other);
		rpn &operator=(rpn other);
		~rpn();
};

#endif