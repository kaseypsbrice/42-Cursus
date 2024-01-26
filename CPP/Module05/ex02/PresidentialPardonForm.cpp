/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:59:15 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 12:14:03 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), target("default")
{
	std::cout << "\033[90m| PresidentialPardonForm Default constructor called |\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target_) : AForm("PresidentialPardonForm", false, 25, 5), target(target_)
{
	std::cout << "\033[90m| PresidentialPardonForm Parameterised constructor called |\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	std::cout << "\033[90m| PresidentialPardonForm Copy constructor called |\e[0m" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "\033[90m| PresidentialPardonForm Assignment operator called |\e[0m" << std::endl;
	if (this != &other)
	{
		this->target = other.getTarget();
		AForm::operator=(other);
	}
	return (*this);
}
/* AForm::operator=(other);
 * Calls the assignment operator of the base class AForm.
 * Makes sure that the class components of each class are
 * properly assigned when an object of the derived class
 * is assigned the value of another object.
 */

 PresidentialPardonForm::~PresidentialPardonForm()
 {
	std::cout << "\033[90m* PresidentialPardonForm Destructor called *\e[0m" << std::endl;
 }

 std::string	PresidentialPardonForm::getTarget() const
 {
	return (this->target);
 }

 void	PresidentialPardonForm::execute() const
 {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
 }
 // To be clear, this was what they wanted us to do in the subject file.