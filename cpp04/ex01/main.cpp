/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/12 15:46:58 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

#define SIZE	10

int main(void)
{
	Animal* animals_tab[SIZE];

	// New
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2)
			animals_tab[i] = new Dog;
		else
			animals_tab[i] = new Cat;
	}

	// Delete
	for (int i = 0; i < SIZE; i++)
		delete animals_tab[i];

	std::cout << "\n=== Test deep copy ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "chasser les chats");

	Dog dog2(dog1);  // copy constructor
	std::cout << "\tdog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "\tdog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	dog2.getBrain()->setIdea(0, "dormir");
	std::cout << "Apres modif dog2 :" << std::endl;
	std::cout << "\tdog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "\tdog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	return (0);
}
