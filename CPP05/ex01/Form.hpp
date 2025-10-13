/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 22:21:19 by scarlucc          #+#    #+#             */
/*   Updated: 2025/10/13 11:18:56 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"


class Form {
    
    private:
        const std::string   name;
        bool               	isSigned;
        const int           gradeToSign;
        const int           gradeToExec;

		public:
		//subject
		std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		//void				beSigned(Bureaucrat& bureaucrat);
		
		
		//orthodox canonical form
		Form();
		~Form();
		Form(const Form &other);
		Form& operator=(const Form& form);

		//more stuff
		Form(std::string startName, int gradeToSign = 150, int gradeToExec = 150);
	
	//exception classes
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
			//virtual ~GradeTooHighException();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
			//virtual ~GradeTooLowException();
	};
};

std::ostream& 		operator<<(std::ostream& os, const Form& form);

#endif