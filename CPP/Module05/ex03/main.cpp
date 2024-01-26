/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:59:31 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/12 15:57:31 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 1);
        Intern theIntern;
        AForm* formArray;

        formArray = theIntern.makeForm("PresidentialPardonForm", "Bender");

        if (formArray != nullptr)
        {
            std::cout << bureaucrat << std::endl;
            bureaucrat.signForm(*formArray);
            bureaucrat.executeForm(*formArray);
            delete formArray;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
/* Reminder to self:
 * The form names are exactly the same as the .cpp/.hpp file names.
 * ... (T.T)
 */