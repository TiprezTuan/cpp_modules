/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:20:51 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:14:38 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

/*
Allocate zombie on the stack : When the object is temporary, used and destroyed within the current scope
Allocate zombie on the heap : When the object needs to survive beyond the current scope
*/

int main(void)
{
	Zombie* horde = zombieHorde(10, "tutu");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
