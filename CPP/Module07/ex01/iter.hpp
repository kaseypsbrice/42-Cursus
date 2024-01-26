/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:07:09 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/22 16:34:43 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *arr, int len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}
// Applies a function to each element of the array

template <typename T>
void print(T const &s)
{
	std::cout << s << std::endl;
}
// Prints the value of the provided type

#endif