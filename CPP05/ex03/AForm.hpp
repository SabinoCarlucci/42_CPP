/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:34:49 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/18 15:34:04 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm {
    
    private:
        const std::string   name;
        bool               	isSigned;
        const int           gradeToSign;
        const int           gradeToExec;
		
		virtual void		doTheThing() const = 0;//set to private in derivate classes
		
	public:
		//subject
		std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned(Bureaucrat& bureaucrat);
		void 				execute(Bureaucrat const & executor) const;
		
		
		//orthodox canonical form
		AForm();
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm& form);

		//more stuff
		AForm(std::string startName, int gradeToSign = 150, int gradeToExec = 150);
	
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

	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
			//virtual ~GradeTooLowException();
	};
};

std::ostream& 		operator<<(std::ostream& os, const AForm& form);

#endif