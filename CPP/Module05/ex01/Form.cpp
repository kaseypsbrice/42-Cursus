/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:10:48 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 09:52:32 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(1), execGrade(1)
{
	std::cout << "\033[90m| Default constructor called |\e[0m" << std::endl;
}
// [*] Default constructor

Form::Form(const std::string &name, bool isSigned, const int signGrade, const int execGrade) : name(name), isSigned(isSigned), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "\033[90m| Parameterised constructor called |\e[0m" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &other) : name(other.getName()), signGrade(other.getSignGrade()), execGrade(other.getExecGrade())
{
	std::cout << "\033[90m| Copy constructor called |\e[0m" << std::endl;
	*this = other;
}
// [*] Copy constructor
// Need to initialise variables of a const value in an initialiser list.
// E.g. Form::Form(const Form &other) : name(other.getName()), signGrade(other.getSignGrade()), etc.

Form &Form::operator=(const Form &other)
{
	std::cout << "\033[90m| Assignment operator called |\e[0m" << std::endl;
	this->isSigned = other.isSigned;
	return (*this);
}
// [*] Assignment operator
// Can't initialise const values within the operator function, so they've
// been initialised in the initialiser list of the copy constructor.
// Only non-const values are allowed in the body of this function.

Form::~Form()
{
	std::cout << "\033[90m* Destructor called *\e[0m" << std::endl;
}
// [*] Destructor

std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getSigned() const
{
	return (this->isSigned);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

int	Form::getExecGrade() const
{
	return (this->execGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form Information: " << std::endl;
	os << "Name: " << form.getName() << std::endl;
	os << "Signed: " << form.getSigned() << std::endl;
	os << "Grade to sign: " << form.getSignGrade() << std::endl;
	os << "Grade to execute: " << form.getExecGrade() << std::endl;
	return (os);
}