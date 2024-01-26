/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:18:37 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/21 16:28:05 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ---------------- Orthodox Canonical Form ------------------ */

ScalarConverter::ScalarConverter()
{
	std::cout << "\033[90m| Default constructor called |\e[0m" << std::endl;
}
// [*] Default constructor

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "\033[90m| Copy constructor called |\e[0m" << std::endl;
	*this = other;
}
// [*] Copy constructor

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "\033[90m| Assignment operator called |\e[0m" << std::endl;
	if (this != &other)
		(void)other;
	return (*this);
}
// [*] Assignment operator

ScalarConverter::~ScalarConverter()
{
	std::cout << "\033[90m* Default destructor called *\e[0m" << std::endl;
}
// [*] Destructor

/* ---------------------- Functions ------------------------ */

void printChar(const std::string input)
{
    std::stringstream ss(input);
    int intValue;

    if (ss >> intValue)
    {
        char c = static_cast<char>(intValue);
        if (std::isprint(c))
            std::cout << "char : '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
}
// Converts input to char and prints 
// - Attempts to extract an int from the input string
// - Explicity converts the int to a char using static_cast
// - Checks whether the char is printable, if not, prints an explanatory message
// - If an int can't be extracted from the string, char: impossible

void	printInt(const std::string input)
{
	int	i;
	std::stringstream ss(input);

	if (ss >> i)
	{
		i = static_cast<int>(std::stoi(input));
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}
// Converts input to int and prints

void	printDouble(const std::string input)
{
	double	d;
	std::stringstream ss(input);

	if (ss >> d)
	{
		d = static_cast<double>(std::stod(input));
		if (d - static_cast<int>(d) == 0)
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}
// Converts input to double and prints 
// (d - static_cast<int>(d) == 0)
// ^ Calculates the difference between the original double value
// and it's integer part. If 'd' is an int, the difference will
// be 0. If 'd' has a fractional part, the difference will be a
// non-zero value.

void	printFloat(const std::string input)
{
	float	f;
	std::stringstream ss(input);

	if (ss >> f)
	{
		f = static_cast<float>(std::stof(input));
		if (f - static_cast<int>(f) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
}
// Converts input to Float and prints
// Similar to the printDouble function, makes the same
// calculation.

void	printPseudoLiterals(const std::string input)
{
	if (input == "-inff" || input == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (input == "+inff" || input == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "nanf" || input == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}
// Prints pseudo-literals

bool	isPseudoLiteral(const std::string input)
{
	const std::string pseudoLiterals[6] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (input == pseudoLiterals[i])
			return (true);
	}
	return (false);
}
// Checks if the input is a pseudo-literal

// std::string	getType(const std::string input)
// {
// 	char	*endptr = nullptr;

// 	if (input.empty())
// 		return ("empty");
// 	if (input.size() == 1 && !std::isdigit(input[0]))
// 		return ("char");

// 	std::strtol(input.c_str(), &endptr, 0);
// 	if (endptr == input.c_str() + input.length())
// 		return ("int");
// 	endptr = nullptr; // Reset for the next conversion
// 	std::strtod(input.c_str(), &endptr);
// 	if (endptr == input.c_str() + input.length())
// 		return ("double");
// 	endptr = nullptr; // Reset
// 	std::strtof(input.c_str(), &endptr);
// 	if ((endptr == input.c_str() + input.length()) || \
// 	(endptr[0] == 'f' && endptr[1] == 0))
// 		return ("float");
// 	return ("unknown");
// }
// This works, I just realised I didn't need it.

void	ScalarConverter::convert(const std::string input)
{
	if (isPseudoLiteral(input) == true)
	{
		printChar(input);
		printInt(input);
		printPseudoLiterals(input);
	}
	else
	{
		//std::string type = getType(input);
		//std::cout << "Type detected: " << type << std::endl;
		//std::cout << "---------------------" << std::endl;
		printChar(input);
		printInt(input);
		printFloat(input);
		printDouble(input);
	}
}
// Prints the same way as the subject file example
