/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:18:20 by scarlucc          #+#    #+#             */
/*   Updated: 2025/07/19 18:49:15 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"



class PhoneBook {
private:
	Contact		contacts[8];
	static int	total_contacts;
	static int	oldest_contact;

public:
//costruttore e distruttore di default, per dichiarazione esplicita
	PhoneBook();
	~PhoneBook();
	
	void		currentContact();
	void		add();
	void		search();
	void		testing();
	
};

#endif