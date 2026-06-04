/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:20:51 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:05:45 by ttiprez          ###   ########.fr       */
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
	Zombie *z = newZombie("tutu");
	z->announce();
	delete z;

	randomChump("clo");
	return (0);
}
