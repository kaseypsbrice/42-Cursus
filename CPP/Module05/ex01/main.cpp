/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:31 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 10:14:47 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat	bureaucrat("Bureaucrat", 51);
		Form		form("form", false, 100, 50);
		std::cout << "Name: " << bureaucrat.getName() << ", score: " << bureaucrat.getGrade() << std::endl;
		bureaucrat.signForm(form);
		std::cout << "\e[0;36mIncremented\e[0m" << std::endl;
		bureaucrat.incrementGrade();
		bureaucrat.signForm(form);

		Bureaucrat	otherBureaucrat("otherBureaucrat", 20);
		std::cout << "Name: " << otherBureaucrat.getName() << ", score: " << otherBureaucrat.getGrade() << std::endl;
		otherBureaucrat.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
/* Reminder: Lower the number, higher the grade. */