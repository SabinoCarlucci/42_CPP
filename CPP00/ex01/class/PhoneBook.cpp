/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:46:08 by scarlucc          #+#    #+#             */
/*   Updated: 2025/07/22 20:05:47 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>

int	PhoneBook::oldest_contact = -1;
int	PhoneBook::total_contacts = 0;

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}


void	PhoneBook::testing()
{
	Contact	testContacts[8] = {
		Contact("Mario", "Rossi", "mariucciooooo", "1234567890", "ciao"),
		Contact("Maria", "Bianchi", "Mimma", "0987654321", "ehila'"),
		Contact("Luigi", "Verdi", "gigi", "1231231234", "cucu'"),
		Contact("Rosa", "Neri", "rosina", "3213214321", "asasasa"),
		Contact("John", "Gialli", "peppino", "1112223333", "bsbsbsbsb"),
		Contact("Giuseppina", "Marroni", "pina", "3332221111", "non ho segreti"),
		Contact("Gaetano", "Calvino", "tano", "1234567890", "sono un pagliaccio"),
		Contact("Giovanni", "Zucchetti", "Gianni", "0987654321", "sono un alieno")
	};

	
	for (int i = 0; i < 8; i++)
		this->contacts[i] = testContacts[i];

	oldest_contact = 7;
	total_contacts = 8;
}

std::string cutString(std::string string)
{
	if (string.length() > 10)
		return (string.substr(0, 9) + ".");
	return (string);
}

void	PhoneBook::search(void)
{
	if (total_contacts == 0)
	{
		std::cout << "No contacts in phonebook" << std::endl;
		return ;
	}
	
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname"
			  << std::endl;
	
	for (int i = 0; total_contacts > i; i++)
	{
		std::cout << std::setw(10) << std::to_string(i) << "|"
				  << std::setw(10) << cutString(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << cutString(contacts[i].getLastName()) << "|"
				  << std::setw(10) << cutString(contacts[i].getNickname())
				  << std::endl;
	}

	std::cout << "Please digit index of contact to display (range 0 - 7)" << std::endl;
	
	std::string index_str;
	int 		index_int;
	if (!std::getline(std::cin, index_str))//in case of errors
	{
		std::cin.clear();
		exit(0);
	}

	if (index_str.empty() || index_str.length() > 1 || index_str[0] > '7' || index_str[0] < '0')
	{
		std::cout << "invalid index (range 0 - 7)" << std::endl;
		return ;
	}	
	else
		index_int = index_str[0] - '0';
	
	//se numero di contatto supera i contatti registrati, errore
	if (index_int > (total_contacts - 1))
	{
		std::cout << "no contacts recorded at index " << index_str << std::endl;
		return ;
	}
		
	//print selected contact information
	std::cout << "First Name: " << contacts[index_int].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index_int].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index_int].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index_int].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index_int].getDarkestSecret() << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	input;
	Contact	now_contact;

	if (total_contacts < 8)
		total_contacts++;
	
	if (oldest_contact == 7)
		oldest_contact = -1;
	oldest_contact++;
	//std::cout << oldest_contact << std::endl;//debug, poi commenta
	
	
	while (input.empty())
	{
		std::cout << "Enter contact first name:" << std::endl;
		std::getline(std::cin, input);
	}
	now_contact.setFirstName(input);
	input = "";

	while (input.empty())
	{
		std::cout << "Enter contact last name:" << std::endl;
		std::getline(std::cin, input);
	}
	now_contact.setLastName(input);
	input = "";
	
	while (input.empty())
	{
		std::cout << "Enter contact nickname:" << std::endl;
		std::getline(std::cin, input);
	}
	now_contact.setNickname(input);
	input = "";

	while (input.empty())
	{
		std::cout << "Enter contact phone number:" << std::endl;
		std::getline(std::cin, input);
	}
	now_contact.setPhoneNumber(input);
	input = "";
	
	while (input.empty())
	{
		std::cout << "Enter contact darkest secret:" << std::endl;
		std::getline(std::cin, input);
	}
	now_contact.setDarkestSecret(input);
	input = "";

	PhoneBook::contacts[oldest_contact] = now_contact;
}