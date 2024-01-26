/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:11:05 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/23 09:22:05 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <exception>
# include <algorithm>
# include <vector>

template<class T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator iter = find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::exception();
	return (iter);
};

#endif