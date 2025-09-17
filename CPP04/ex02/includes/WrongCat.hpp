/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 23:05:20 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/17 11:23:25 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		virtual ~WrongCat();
		WrongCat& operator=(const WrongCat& other);
		void makeSound() const;
};

#endif