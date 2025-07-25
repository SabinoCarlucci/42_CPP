/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:54:22 by scarlucc          #+#    #+#             */
/*   Updated: 2025/07/07 10:14:51 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/Contact.hpp"

Contact::Contact() {}  //default constructor
Contact::~Contact() {} //default destructor

//parametric constructor for easy testing
Contact::Contact(
		const std::string &firstName,
		const std::string &lastName,
		const std::string &nickname,
		const std::string &phoneNumber,
		const std::string &darkestSecret
		) :
		firstName(firstName),
		lastName(lastName),
		nickname(nickname),
		phoneNumber(phoneNumber),
		darkestSecret(darkestSecret)
{
	return ;
}

//setters
void	Contact::setFirstName(const std::string &value) {
	firstName = value;
}
void	Contact::setLastName(const std::string &value) {
	lastName = value;
}
void	Contact::setNickname(const std::string &value) {
	nickname = value;
}
void	Contact::setPhoneNumber(const std::string &value) {
	phoneNumber = value;
}
void	Contact::setDarkestSecret(const std::string &value) {
	darkestSecret = value;
}

//getters
std::string	Contact::getFirstName() const {
	return firstName;
}
std::string	Contact::getLastName() const {
	return lastName;
}
std::string	Contact::getNickname() const {
	return nickname;
}
std::string	Contact::getPhoneNumber() const {
	return phoneNumber;
}
std::string	Contact::getDarkestSecret() const {
	return darkestSecret;
}
