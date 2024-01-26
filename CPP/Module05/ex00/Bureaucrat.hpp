/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:26 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/11 18:22:31 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat 
{
	private:
		const std::string	name;
		int					grade;

	public:
		// Orthodox canonical form
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Functions mentioned in subject file
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif