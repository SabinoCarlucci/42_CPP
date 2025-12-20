/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:37:16 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/20 17:22:56 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif