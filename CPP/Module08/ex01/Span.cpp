/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:43:26 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/23 17:11:26 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	size = 0;
}
// Constructor

Span::Span(unsigned int N)
{
	size = N;
}
// Parameterised constructor

Span::Span(const Span &other)
{
	*this = other;
}
// Copy constructor

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		size = other.size;
		values = other.values;
	}
	return (*this);
}
// Assignment operator

Span::~Span() {}
// Destrutctor

/* ------------------- Functions ------------------- */

void Span::addNumber(int nb)
{
	if (values.size() >= size)
		throw std::exception();
	values.push_back(nb);
}
// If the values vector is full, it'll throw an exception.
// Otherwise, it'll add the number to the end of the vector.

int Span::shortestSpan()
{
	std::vector<int>	temp = values;
	int					shortSpan;

	sort(temp.begin(), temp.end());
	shortSpan = temp[1] - temp[0];
	for (unsigned int i = 1; i < temp.size() - 1; i++) {
		if (temp[i + 1] - temp[i] < shortSpan)
			shortSpan = temp[i + 1] - temp[i];
	}
	temp.clear();
	return (shortSpan);
}
// - Sorts the temp vector in ascending order.
// - Initialises shortSpan with the difference between the first
//   two elements in the vector.
// - Continues to compare the differences between elements until
//   the shortest span is found.

int Span::longestSpan()
{
	std::vector<int>	temp = values;
	int					longSpan;

	sort(temp.begin(), temp.end());
	longSpan = *(temp.end() - 1) - *(temp.begin());
	temp.clear();
	return (longSpan);
}
// - Sorts the temp vector in ascending order.
// - Calculates the difference between the last and first elements.

void	Span::addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const end)
{
	if (std::distance(begin, end) > static_cast<long>(size - values.size()))
		throw std::exception();
	values.insert(values.end(), begin, end);
}
// - Checks whether adding to the vector would exceed the size of the vector.
// - Throws an exception if it does exceed the size.
// - Otherwise, inserts the values to the end of the vector.