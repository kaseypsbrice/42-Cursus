/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:41:05 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/21 17:03:24 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ---------------- Orthodox Canonical Form ------------------ */

Serializer::Serializer()
{
	std::cout << "\033[90m| Default constructor called |\e[0m" << std::endl;
}
// [*] Default constructor

Serializer::Serializer(const Serializer &other)
{
	std::cout << "\033[90m| Copy constructor called |\e[0m" << std::endl;
	*this = other;
}
// [*] Copy constructor

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << "\033[90m| Assignment operator called |\e[0m" << std::endl;
	if (this != &other)
		(void)other;
	return (*this);
}
// [*] Assignment operator

Serializer::~Serializer()
{
	std::cout << "\033[90m* Default destructor called *\e[0m" << std::endl;
}
// [*] Destructor

/* ---------------------- Functions ------------------------ */

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
// - Takes a pointer to a data structure
// - Converts it to a uintptr_t (unsigned integer type for 
// 	 storing pointers)

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
// - Takes the uintptr_t and converts it back to a pointer 
//   to a data structure