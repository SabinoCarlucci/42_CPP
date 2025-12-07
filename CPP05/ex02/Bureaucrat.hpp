/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:57 by scarlucc          #+#    #+#             */
/*   Updated: 2025/12/07 18:35:21 by scarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "AForm.hpp"


class Form;

class Bureaucrat {
	
	private:
		const std::string 	name;
		int 				grade;

	
	public:
		//subject
		int					getGrade() const;
		std::string			getName() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form);
		
		//orthodox canonical form
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);

		//more stuff
		Bureaucrat(std::string name, int grade = 150);
		void		setGrade(std::string startGrade);
	
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

std::ostream& 		operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif