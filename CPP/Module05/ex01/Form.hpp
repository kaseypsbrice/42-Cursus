/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:10:45 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 09:06:16 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		// Required private variables
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			execGrade;
	
	public:
		// Orthodox canonical form
		Form();
		Form(const std::string &name, bool isSigned, const int signGrade, const int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		// Additional functions
		std::string			getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		void	beSigned(const Bureaucrat &bureaucrat);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw() {return "Grade too high";};
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw() {return "Grade too low";};
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif