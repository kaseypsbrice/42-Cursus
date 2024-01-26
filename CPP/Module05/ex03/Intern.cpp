/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:25:33 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 15:50:47 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "\033[90m| Intern Default constructor called |\e[0m" << std::endl;
}
// [*] Default constructor

Intern::Intern(const Intern &other)
{
	std::cout << "\033[90m| Intern Copy constructor called |\e[0m" << std::endl;
	*this = other;
}
// [*] Copy constructor

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "\033[90m| Intern Assignment operator called |\e[0m" << std::endl;
	if (this != &other)
		(void)other;
	return (*this);
}
// [*] Assignment operator

Intern::~Intern()
{
	std::cout << "\033[90m* Intern Destructor called *\e[0m" << std::endl;
}
// [*] Destructor

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	const std::string formNames[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"};

	AForm *(*forms[3])(std::string const &target) = {
		&ShrubberyCreationForm::create,
		&RobotomyRequestForm::create,
		&PresidentialPardonForm::create};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i](target));
		}
	}
	std::cerr << "Intern cannot create " << formName << std::endl;
	return (NULL);
}
/* - Array of names
 * - An array of function pointers to create instances of each form
 * - Loop to create the forms
 */