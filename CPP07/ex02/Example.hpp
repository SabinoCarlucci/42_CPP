/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:18:45 by scarlucc          #+#    #+#             */
/*   Updated: 2026/01/20 16:52:18 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>

class Example
{
	private:
		int		someNumber;
	
	public:
		Example();
		Example(const Example &other);
		virtual ~Example();
		void setSomeNumber(int newNumber);
		int getSomeNumber() const;
		Example &operator=(const Example &other);
};

std::ostream &operator<<(std::ostream &os, const Example &other);

#endif