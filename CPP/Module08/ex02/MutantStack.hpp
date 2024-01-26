/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:21:22 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/24 09:12:33 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(MutantStack const &other) : MutantStack<T>::stack(other) {}
		~MutantStack() {}

		MutantStack<T> &operator=(MutantStack<T> const &other) {
			if (this != &other)
				MutantStack<T>::stack::operator=(other);
			return (*this);
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator constIterator;

		iterator begin() {return std::stack<T>::c.begin();}
		iterator end() {return std::stack<T>::c.end();}
		constIterator begin() const {return std::stack<T>::c.begin();}
		constIterator end() const {return std::stack<T>::c.end();}
		// Used to point to the first and last elements in the stack
};

#endif