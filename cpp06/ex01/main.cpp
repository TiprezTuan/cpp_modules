/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:41:11 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/01 13:23:32 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	// New data t1
	Data* t1 = new Data;
	t1->id = 1;
	t1->message = "Bonjour a tous";
	std::cout << "--- t1 ---" << std::endl;
	std::cout << "id = " << t1->id << std::endl;
	std::cout << "message = " << t1->message << std::endl;

	// Serialisation
	uintptr_t serialiezedData = Serializer::serialize(t1);

	// New data t2 + deserialisation
	Data *t2 = Serializer::deserialize(serialiezedData);
	// Test est-ce que se sont les memes ?
	if (t1 == t2)
		std::cout << "t1 == t2" << std::endl;
	else
		std::cout << "t1 != t2" << std::endl;

	std::cout << "--- t2 ---" << std::endl;
	std::cout << "id = " << t2->id << std::endl;
	std::cout << "message = " << t2->message << std::endl;

	// Modifiction t2 (donc t1)
	t2->message = "Nouveau message";
	std::cout	<< "message t2 = " << t2->message
				<< "\nmessage t1 = " << t1->message << std::endl;

	return 0;
}
