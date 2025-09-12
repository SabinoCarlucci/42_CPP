/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rewrite.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:19:41 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/11 19:31:23 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <string>
#include <iostream>
#include <fstream>

#ifndef REWRITE_HPP
#define REWRITE_HPP

class Rewrite
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;

		std::string getFile() const;
		
		void 		setFile(const std::string &newContent) const;

		
	public:
		Rewrite(std::string filename, std::string s1, std::string s2);
		void rewriteFile() const;
};

#endif