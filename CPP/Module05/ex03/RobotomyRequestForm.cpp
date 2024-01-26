/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:14:26 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 15:35:41 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), target("default")
{
	std::cout << "\033[90m| RobotomyRequestForm Default constructor called |\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target_) : AForm("RobotomyRequestForm", false, 72, 45), target(target_)
{
	std::srand(std::time(NULL));
	std::cout << "\033[90m| RobotomyRequestForm Parameterised constructor called |\e[0m" << std::endl;
}
/* std::time(NULL) is used to get the current time
 * std::srand() sets up the starting point for a random number generator
 * Using the current time as a parameter/seed, it ensures that we get a different
 * set of random numbers each time.
 */

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	std::cout << "\033[90m| RobotomyRequestForm Copy constructor called |\e[0m" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "\033[90m| RobotomyRequestForm Assignment operator called |\e[0m" << std::endl;
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

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[90m* RobotomyRequestForm Destructor called *\e[0m" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute() const
{
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
/* Specifically need it to be successful 50% of the time.
 * So, rand() % 2 is pretty much a coin toss.
 * It'll randomly generate either 1 or 0.
 * If it's 0 then it'll be successful, otherwise it'll fail.
 */

AForm *RobotomyRequestForm::create(std::string const &target)
{
	return new RobotomyRequestForm(target);
}