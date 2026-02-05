/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:10:58 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/05 17:13:52 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class Rpn
{
	private:
		std::stack<int> _st;
	
	public:
		Rpn();
		Rpn(const std::string &expression);//construct and execute
		Rpn(const Rpn &other);
		Rpn &operator=(Rpn other);
		~Rpn();

	class WrongInputException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NotEnoughOperandsException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class DivisionByZeroException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class TooManyOperandsException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif