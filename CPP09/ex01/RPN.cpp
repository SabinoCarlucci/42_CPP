/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:11:30 by scarlucc          #+#    #+#             */
/*   Updated: 2026/02/05 17:59:43 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

Rpn::Rpn()
{
	
}

Rpn::Rpn(const Rpn &other) : _st(other._st)
{
	
}

Rpn &Rpn::operator=(Rpn other)
{
	if (this != &other)
		this->_st = other._st;
	return *this;
}

Rpn::~Rpn()
{
	
}

/* $> ./Rpn "1 2 * 2 / 2 * 2 4 - +"
0

2 2 / 2 * 2 4 - +
1 2 * 2 4 - +
2 2 4 - +  => (2 - 4) 2 +  => second to last operand = left, last operand = right
-2 + 2 = 0
*/

Rpn::Rpn(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;
	int a;
	int b;
	int result;
	
	while(ss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))//serve fare anche numeri negativi?
			_st.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			//check operands
			if (_st.size() < 2)
				throw NotEnoughOperandsException();
			
			//execute
			b = _st.top(); _st.pop(); //right operand (es. a / b)
			a = _st.top(); _st.pop(); //left operand (es. a / b)
			
			if (token == "+") result = a + b;
			else if (token == "-") result = a - b;
			else if (token == "*") result = a * b;
			else if (token == "/")
			{
				if (b == 0)
					throw DivisionByZeroException();
				result = a / b;
			}
			_st.push(result);
		}
		else
			throw WrongInputException();
	}
	
	//check for too many operands
	if (_st.size() != 1)
		throw TooManyOperandsException();

	std::cout << _st.top() << std::endl;
}


const char *Rpn::WrongInputException::what() const throw()
{
	return "Error: wrong input";
}

const char *Rpn::NotEnoughOperandsException::what() const throw()
{
	return "Error: not enough operands";
}

const char *Rpn::DivisionByZeroException::what() const throw()
{
	return "Error: reality imploded";
}

const char *Rpn::TooManyOperandsException::what() const throw()
{
	return "Error: too many operands";
}