/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:13:23 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/22 16:28:54 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
{
	_size = 0;
	array = new T[0];
}
// Default constructor

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	array = new T[n];
}
// Parameterised constructor

template <typename T>
Array<T>::Array(const Array &other)
{
	_size = other._size;
	array = new T[_size];
	
	for (unsigned int i = 0; i < _size; i++) {
		array[i] = other.array[i];
	}
}
// Copy constructor

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] array;
		array = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++) {
			array[i] = other.array[i];
		}
	}
	return (*this);
}
// Assignment operator

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::exception();
	return (array[i]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}
// Size function that returns the number of elements
// in the array.

template <typename T>
Array<T>::~Array(void)
{
	delete[] array;
}
// Destructor
