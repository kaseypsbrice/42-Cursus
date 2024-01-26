/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:43:09 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/25 08:04:01 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL)); // Makes sure any numbers randomly generated are actually random
	
	// ----------------- Subject file tests ----------------- //
	// - Adds numbers to the span
	// - Prints what the shortest & longest span is
	try 
	{
		std::cout << "\e[0;33m--- Tests from the subject file ---\e[0m" << std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
	// ----------------- Testing exceptions ----------------- //
	// - Will throw an exception because there's more numbers
	//   than the size of the span
	try
	{
		std::cout << "\e[0;33m--- Additional tests ---\e[0m" << std::endl;

		std::cout << "\e[0;35m- Testing the exceptions -\e[0m" << std::endl;
    	Span sp2 = Span(8);
    	sp2.addNumber(4);
    	sp2.addNumber(8);
   		sp2.addNumber(2);
    	sp2.addNumber(12);
    	sp2.addNumber(6);
    	sp2.addNumber(15);
    	sp2.addNumber(10);
    	sp2.addNumber(5);
		sp2.addNumber(98);
    	std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    	std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ----------------- Testing addRange function ----------------- //
	// - Using a vector of numbers, adds the array to the span using
	//   the addRange function
	try
	{
		std::cout << "\n\e[0;35m- Testing addRange function -\e[0m" << std::endl;
		Span sp2 = Span(8);
		int arr[] = {100, 200, 300, 400, 500};
    	std::vector<int> vectNumbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
    	sp2.addRange(vectNumbers.begin(), vectNumbers.end());
    	std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    	std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ----------------- Testing large vector sizes (10,000) ----------------- //
	// - Creates a vector to store a large array of randomly generated numbers
	// - Randomly generates numbers up to the value of 100,000
	// - Instantiates the span and makes sure that the vectSize is greater than
	//	 the number of elements in the array
	// - Adds all the numbers to the span using addRange
	try
	{
		std::cout << "\n\e[0;35m- Testing with a vector size of 10,000 -\e[0m" << std::endl;
		const int vectSize = 10000;
    	std::vector<int> randVector;
    	for (int i = 0; i < vectSize; ++i)
    	{
        	randVector.push_back(rand() % 100000);
    	}
        Span sp = Span(vectSize + 100);
        sp.addRange(randVector.begin(), randVector.end());
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// ----------------- Testing large vector sizes (100,000) ----------------- //
	try
	{
		std::cout << "\n\e[0;35m- Testing with a vector size of 100,000 -\e[0m" << std::endl;
		const int vectSize = 100000;
    	std::vector<int> randVector;
    	for (int i = 0; i < vectSize; ++i)
    	{
        	randVector.push_back(rand() % 1000000);
    	}
        Span sp = Span(vectSize + 100);
        sp.addRange(randVector.begin(), randVector.end());
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	return 0;
}
/* Test 1: Same test as in the subject file
 * Test 2: Making sure the exceptions work
 * Test 3: Using the addRange function
 * Test 4: A test using 10,000 numbers
 * Test 5: Tests using 100,000 numbers :)
 */