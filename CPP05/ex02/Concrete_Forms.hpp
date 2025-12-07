/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Concrete_Forms.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:48:09 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/07 19:51:48 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCRETE_FORMS_HPP
#define CONCRETE_FORMS_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : AForm {
    
};

std::ostream& 		operator<<(std::ostream& os, const AForm& form);

#endif