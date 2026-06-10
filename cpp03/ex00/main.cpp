/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:52:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 13:20:59 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
	ClapTrap	entity("Jack");

	// Bases
	entity.attack("Paul");
	entity.takeDamage(2);
	entity.beRepaired(2);

	// Vider l'energie
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");
	entity.attack("Jean");

	// Mort
	entity.takeDamage(1000);
	
	return (0);
}
