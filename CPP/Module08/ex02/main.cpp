/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:48:09 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/24 09:17:26 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() 
{
    // Create a MutantStack of integers
    MutantStack<int> mutantStack;

    // Push some values onto the stack
    mutantStack.push(10);
    mutantStack.push(20);
    mutantStack.push(30);
    mutantStack.push(40);

    // Print the elements using iterators
    std::cout << "Elements in MutantStack using iterator:" << std::endl;
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Print the elements using const_iterator
    const MutantStack<int>& constStack = mutantStack;
    std::cout << "\nElements in MutantStack using const_iterator:" << std::endl;
    for (MutantStack<int>::constIterator it = constStack.begin(); it != constStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test stack operations
    std::cout << "Top element: " << mutantStack.top() << std::endl;
    std::cout << "Stack size: " << mutantStack.size() << std::endl;

    // Pop an element and print the updated stack
    mutantStack.pop();
    std::cout << "\nAfter pop, elements in MutantStack using iterator:" << std::endl;
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Clear the stack and print the size
    mutantStack.pop();
    mutantStack.pop();
    mutantStack.pop();
    std::cout << "\nAfter clear, stack size: " << mutantStack.size() << std::endl;

    return 0;
}