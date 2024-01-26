/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:06:48 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/22 11:31:42 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void square(int const &n)
{
	std::cout << n * n << std::endl;
}

int main(void)
{
	int array[] = {2, 4, 6, 8};

	::iter(array, 4, square);

	std::string strings[] = {"Adelaide", "Perth", "Darwin", "Cairns"};
	
	::iter(strings, 4, print);
}