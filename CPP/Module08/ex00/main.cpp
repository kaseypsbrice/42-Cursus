/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:11:02 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/25 08:02:02 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(arr[0]));

    try
    {
        int n = 5;
		std:: cout << "\n\e[0;33m--- Test 1 ---\e[0m" << std::endl;
		std:: cout << "Searching for " << n << " in the container" << std::endl;
        std::vector<int>::iterator result = easyfind(vect, n);
        std::cout << "\e[0;32m| SUCCESS |\e[0m Value " << n << " found at position: " << std::distance(vect.begin(), result) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Cannot find the value in the container" << std::endl;
    }

    try
    {
        int n = 15;
		std:: cout << "\n\e[0;33m--- Test 2 ---\e[0m" << std::endl;
		std:: cout << "Searching for " << n << " in the container" << std::endl;
        std::vector<int>::iterator result = easyfind(vect, n);
        std::cout << "\e[0;32m| SUCCESS |\e[0m Value '" << n << "' found at position: " << std::distance(vect.begin(), result) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "\e[0;31m| FAILED |\e[0m Cannot find the value in the container" << std::endl;
    }
	
	std::cout << std::endl;

    return 0;
}
/*
 * _Vectors_
 * A vector is a dynamic array that can resize itself automatically
 * when elements are added and removed. They are apart of the 
 * Standard Template Library (STL).
 *
 * In C++, "containers" are classes or data structures that can hold
 * multiple elements. So this includes arrays, lists, queues, stacks,
 * and maps.
 */