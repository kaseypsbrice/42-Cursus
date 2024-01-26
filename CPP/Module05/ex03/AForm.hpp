/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:30:04 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 15:25:33 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		int					signGrade;
		int					execGrade;
		virtual void		execute() const = 0;
		// ^ Makes the class abstract
		// It cannot be instantiated directly, but is used by
		// derived classes. Derived classes must provide
		// their own implementation of the execute() function.
	public:
		// Orthodox canonical form
		AForm();
		AForm(const std::string &name, bool isSigned, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		// ^ Ensures that everything from the base class and derived 
		// classes is destroyed properly.

		// Get functions
		std::string			getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		// Set functions
		void				setName(std::string name);
		void				setSigned(bool sign);
		void				setSignGrade(int sign);
		void				setExecGrade(int sign);
		
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const;
		// ^ Is a default implementation of the base class that can be
		// overridden by derived classes.

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw() {return "Grade too high";};
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw() {return "Grade too low";};
		};
		class NotSignedException : public std::exception
		{
			virtual const char *what() const throw() {return "Not signed";};
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif