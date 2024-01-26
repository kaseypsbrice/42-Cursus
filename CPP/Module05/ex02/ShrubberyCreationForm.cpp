/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:25:51 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 14:13:15 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("default")
{
	std::cout << "\033[90m| ShrubberyCreationForm Default constructor called |\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target_) : AForm("ShrubberyCreationForm", false, 145, 137), target(target_)
{
	std::cout << "\033[90m| ShrubberyCreationForm Parameterised constructor called |\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "\033[90m| ShrubberyCreationForm Copy constructor called |\e[0m" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "\033[90m| ShrubberyCreationForm Assignment operator called |\e[0m" << std::endl;
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

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[90m* ShrubberyCreationForm Destructor called *\e[0m" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute() const
{
	std::ofstream ofs(this->getTarget() + "_shrubbery");
	if (!ofs)
	{
		std::cerr << "cannot create file" << std::endl;
		return ;
	}
	ofs << R"(        # #### ####)" << std::endl;
	ofs << R"(      ### \/#|### |/####)" << std::endl;
	ofs << R"(     ##\/#/ \||/##/_/##/_#)" << std::endl;
	ofs << R"(   ###  \/###|/ \/ # ###)" << std::endl;
	ofs << R"( ##_\_#\_\## | #/###_/_####)" << std::endl;
	ofs << R"(## #### # \ #| /  #### ##/##)" << std::endl;
	ofs << R"( __#_--###`  |{,###---###-~)" << std::endl;
	ofs << R"(           \ }{)" << std::endl;
	ofs << R"(            }}{)" << std::endl;
	ofs << R"(            }}{)" << std::endl;
	ofs << R"(            {{})" << std::endl;
	ofs << R"(      , -=-~{ .-^- _)" << std::endl;
	ofs << R"(            `})" << std::endl;
	ofs << R"(             {)" << std::endl;
	ofs.close();
	std::cout << this->getTarget() << "_shubbery created" << std::endl;
}
// Creates a file and puts an ASCII tree in it