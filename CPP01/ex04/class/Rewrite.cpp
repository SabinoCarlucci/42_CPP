/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rewrite.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:19:30 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/12 19:51:41 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Rewrite.hpp"

Rewrite::Rewrite(std::string filename, 
		std::string s1, 
		std::string s2)
		
		: filename(filename),
	 	 s1(s1),
	 	 s2(s2)
{}

std::string Rewrite::getFile() const
{
	std::fstream oldFile(this->filename.c_str());
	if (oldFile.is_open())
	{
		//leggi file da inizio a fine.
		std::string	oldBuffer((std::istreambuf_iterator<char>(oldFile)), std::istreambuf_iterator<char>());
		oldFile.close();
		return oldBuffer;
	}
	else
		throw std::runtime_error("Error: could not open file " + this->filename);
}

void Rewrite::setFile(const std::string &newContent) const
{
	std::string newFileName = this->filename + ".replace";
	std::fstream newFile(newFileName.c_str(), std::ios::out);
	if (newFile.is_open())
	{
		newFile << newContent;
		newFile.close();
	}
	else
		throw std::runtime_error("Error: could not open file " + newFileName);
}

void Rewrite::rewriteFile() const
{
	std::string oldBuffer = this->getFile();
	std::string rewrittenBuffer;
	size_t pos = 0;//posizione corrente in oldBuffer
	size_t posS1; //posizione di s1 trovata

	posS1 = oldBuffer.find(s1, pos);

	while (posS1 != -1)
	{
		//posS1 = oldBuffer.find(s1, pos);
		//rewrittenBuffer.append(stringa_da_appendere, inizio, lunghezza);
		rewrittenBuffer.append(oldBuffer, pos, posS1 - pos);
		rewrittenBuffer.append(s2);
		pos = posS1 + s1.length();
		posS1 = oldBuffer.find(s1, pos);
	}
	//append resto del file
	rewrittenBuffer.append(oldBuffer, pos, posS1 - pos);
	//poi scrivi nel nuovo file
	this->setFile(rewrittenBuffer);
}