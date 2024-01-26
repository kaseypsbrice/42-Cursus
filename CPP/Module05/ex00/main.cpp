/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:31 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 08:33:49 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("a", 120);

	try
	{
		std::cout << "\e[0;36mOriginal:\e[0m" << std::endl;
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << "\e[0;36mIncrement:\e[0m" << std::endl;
		std::cout << a << std::endl;
		std::cout << "\e[0;36mDecrement (same no.):\e[0m" << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n" << "--------------------------" << "\n" << std::endl;

	Bureaucrat b("b", 150);

	try
	{
		std::cout << "\e[0;36mOriginal:\e[0m" << std::endl;
		std::cout << b << std::endl;
		std::cout << "\e[0;36mDecrement:\e[0m" << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Bureaucrat c("c", 1);
	
	// try
	// {
	//	std::cout << "\e[0;36mOriginal:\e[0m" << std::endl;
	//	std::cout << c << std::endl;
	//	std::cout << "\e[0;36mIncrement (same no.):\e[0m" << std::endl;
	// 	c.incrementGrade();
	// 	std::cout << c << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	std::cout << "\n" << "--------------------------" << "\n" << std::endl;
}
/* "a" shows a standard output of what's expected
 * b & c show the exceptions being thrown */