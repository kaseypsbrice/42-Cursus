/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:25:18 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/22 10:03:16 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	/* Test from the subject file */
	std:: cout << "\e[0;33mSubject File Test:\e[0m" << std::endl;

	int a = 2;
	int b = 3;
	
	std::cout << "--- Int ---" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << "\n--- String ---" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	/* ------ Additional testing ------ */
	std::cout << "\n\e[0;33mAdditional Testing:\e[0m" << std::endl;

	float a1 = 16.12;
	float b1 = 19.01;

	std::cout << "--- Float ---" << std::endl;
	::swap(a1, b1);
	std::cout << "a1 = " << a1 << ", b1 = " << b1 << std::endl;
	std::cout << "min( a1, b1 ) = " << ::min( a1, b1 ) << std::endl;
	std::cout << "max( a1, b1 ) = " << ::max( a1, b1 ) << std::endl;
	
	double a2 = 0.14159;
	double b2 = 0.7321;

	std::cout << "\n--- Double ---" << std::endl;
	::swap(a2, b2);
	std::cout << "a2 = " << a2 << ", b2 = " << b2 << std::endl;
	std::cout << "min( a2, b2 ) = " << ::min( a2, b2 ) << std::endl;
	std::cout << "max( a2, b2 ) = " << ::max( a2, b2 ) << std::endl;

	return 0;
}
