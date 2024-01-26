/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:31 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 14:15:25 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat	bureaucrat("bureaucrat", 1);
		ShrubberyCreationForm	shrubbery("shrub");
		PresidentialPardonForm 	presidential("pres");
		RobotomyRequestForm		robotomy("robo");
		
		std::cout << bureaucrat << std::endl;
		std::cout << shrubbery;
		std::cout << presidential;
		std::cout << robotomy;
		
		std::cout << "\n" << std::endl;

		bureaucrat.signForm(shrubbery);
		bureaucrat.signForm(presidential);
		bureaucrat.signForm(robotomy);
		
		bureaucrat.executeForm(shrubbery);
		bureaucrat.executeForm(presidential);
		bureaucrat.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
