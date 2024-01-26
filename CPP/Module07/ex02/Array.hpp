/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:09:47 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/22 16:28:20 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array
{
	private:
		T				*array;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		T& operator[](unsigned int i) const;
		unsigned int size(void) const;
		~Array(void);
};

# include "Array.tpp"

#endif