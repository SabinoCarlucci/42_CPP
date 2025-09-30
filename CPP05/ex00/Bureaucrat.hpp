/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 19:35:57 by scarlucc          #+#    #+#             */
/*   Updated: 2025/09/30 18:51:24 by scarlucc         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <sstream>

class Bureaucrat {
	
	private:
		const std::string name;
		unsigned int 			grade;

	
	public:
		//subject
		unsigned int		getGrade();
		std::string			getName();
		void				incrementGrade();
		void				decrementGrade();
		
		//orthodox canonical form
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& bureaucrat);

		//more stuff
		Bureaucrat(std::string name, unsigned int grade = 150);
		void		setGrade(std::string startGrade);
	
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& 		operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif