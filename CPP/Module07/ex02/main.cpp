/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:13:17 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/22 16:39:03 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		
		std::string s[] = {"Hello", "World", "!"};
		Array<int> a(5);
		Array<std::string> b(3);
		for (int i = 0; i < 5; i++)
		{
			a[i] = i;
			std::cout << a[i] << std::endl;
		}
		for (int i = 0; i < 3; i++)
		{
			b[i] = s[i];
			std::cout << b[i] << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

/* If you purposely want to trigger an exception */
// int main()
// {
//     try
//     {
//         std::string s[] = {"Hello", "World", "!"};
//         Array<int> a(5);
//         Array<std::string> b(3);

//         for (int i = 0; i < 5; i++)
//         {
//             a[i] = i;
//             std::cout << a[i] << std::endl;
//         }

//         // Accessing an index greater than or equal to the size of the array
//         // will trigger the std::exception.
//         int invalidIndex = 10;
//         std::cout << a[invalidIndex] << std::endl;

//         for (int i = 0; i < 3; i++)
//         {
//             b[i] = s[i];
//             std::cout << b[i] << std::endl;
//         }
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     return 0;
// }