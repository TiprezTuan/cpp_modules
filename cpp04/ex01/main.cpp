/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:07:41 by ttiprez          ###   ########.fr       */
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

	return (0);
}
