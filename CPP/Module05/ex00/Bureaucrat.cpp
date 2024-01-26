/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:05 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 10:16:43 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(1)
{
	std::cout << "\033[90m| Default constructor called |\e[0m" << std::endl;
}
// [*] Default constructor

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	std::cout << "\033[90m| Parameterised constructor called |\e[0m" << std::endl;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}
/* "Any attempt to instantiate a Bureucrat using an invalid grade must
 * throw an exception."
 */

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "\033[90m| Copy constructor called |\e[0m" << std::endl;
	*this = other;
}
// [*] Copy constructor

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "\033[90m| Assignment operator called |\e[0m" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}
// [*] Assignment operator

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[90m* Destructor called *\e[0m" << std::endl;
}
// [*] Destructor

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade--;
}
/* Reminder: Grade 1 is the highest grade and 150 is the lowest
 */

void	Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
// Overload of an insertion (<<) operator