/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:10:48 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 14:24:40 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("AForm"), isSigned(false), signGrade(1), execGrade(1)
{
	std::cout << "\033[90m| Default constructor called |\e[0m" << std::endl;
}
// [*] Default constructor

AForm::AForm(const std::string &name, bool isSigned, const int signGrade, const int execGrade) : name(name), isSigned(isSigned), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "\033[90m| Parameterised constructor called |\e[0m" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	if (signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &other) : name(other.getName()), signGrade(other.getSignGrade()), execGrade(other.getExecGrade())
{
	std::cout << "\033[90m| Copy constructor called |\e[0m" << std::endl;
	*this = other;
}
// [*] Copy constructor
// Need to initialise variables of a const value in an initialiser list.
// E.g. Form::Form(const Form &other) : name(other.getName()), signGrade(other.getSignGrade()), etc.

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "\033[90m| Assignment operator called |\e[0m" << std::endl;
	this->isSigned = other.isSigned;
	return (*this);
}
// [*] Assignment operator
// Can't initialise const values within the operator function, so they've
// been initialised in the initialiser list of the copy constructor.
// Only non-const values are allowed in the body of this function.

AForm::~AForm()
{
	std::cout << "\033[90m* Destructor called *\e[0m" << std::endl;
}
// [*] Destructor

std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSigned() const
{
	return (this->isSigned);
}

int	AForm::getSignGrade() const
{
	return (this->signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->execGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
	os << "Form Information: " << std::endl;
	os << "Name: " << form.getName() << std::endl;
	os << "Signed: " << form.getSigned() << std::endl;
	os << "Grade to sign: " << form.getSignGrade() << std::endl;
	os << "Grade to execute: " << form.getExecGrade() << std::endl;
	return (os);
}

/* ---------- New Functions for Ex02 ---------------- */

void	AForm::setName(std::string name)
{
	const_cast<std::string &>(this->name) = name;
}
/* Because name is a const, we need to use const_cast.
 * It temporarily makes it not a const.
 */

void	AForm::setSigned(bool sign)
{
	this->isSigned = sign;
}

void	AForm::setSignGrade(int sign)
{
	this->signGrade = sign;
}

void	AForm::setExecGrade(int sign)
{
	this->execGrade = sign;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::NotSignedException());
	else if (executor.getGrade() > this->getExecGrade())
		throw (GradeTooLowException());
	this->execute();
}