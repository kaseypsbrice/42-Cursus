/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:18:43 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/21 16:28:01 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <cstring>
# include <cstdlib>
# include <cstdio>
# include <cmath>
# include <exception>

class ScalarConverter
{
	private:
		ScalarConverter();
		// "As this class doesn’t need to store anything at all, 
		// this class must not be instantiable by users."
		// Making the constructor private will prevent users
		// from instantiating it.
		// It can only be used through members of it's class.
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		~ScalarConverter();
		
		static void				convert(const std::string input);
};

void	printChar(char c);
void	printInt(const std::string input);
void	printDouble(const std::string input);
void	printFloat(const std::string input);

#endif