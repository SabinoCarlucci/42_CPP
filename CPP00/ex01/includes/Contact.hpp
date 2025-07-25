/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:53:39 by scarlucc          #+#    #+#             */
/*   Updated: 2025/07/17 19:33:16 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();//costruttore di default
	Contact(
		const std::string &firstName,
		const std::string &lastName,
		const std::string &nickname,
		const std::string &phoneNumber,
		const std::string &darkestSecret
	);//costruttore per test
	~Contact();//distruttore default

	//setters
	void setFirstName(const std::string& value);
	void setLastName(const std::string& value);
	void setNickname(const std::string& value);
	void setPhoneNumber(const std::string& value);
	void setDarkestSecret(const std::string& value);

	//getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
