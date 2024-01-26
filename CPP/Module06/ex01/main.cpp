/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrice <kbrice@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:30:19 by kbrice            #+#    #+#             */
/*   Updated: 2024/01/21 17:10:50 by kbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data entry;

	entry.name = "Kasey";
	entry.age = 22;

	uintptr_t out = Serializer::serialize(&entry);

	Data *data = Serializer::deserialize(out);

	std::cout << "Name: " << data->name << std::endl;
	std::cout << "Age: " << data->age << std::endl;
}
/* Serialization is like saving a snapshot of data.
 * Deserialization is using that snapshot to 
 * then recreate the same object later on.
 */