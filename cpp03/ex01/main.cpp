/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:52:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 13:52:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
	ClapTrap	entity("Jack");
	ScavTrap	entity2("Jean");

	// Affichage stats
	std::cout << "Claptrap stats:" << std::endl;
	std::cout << "\tname    = " << entity.getName() << std::endl;
	std::cout << "\thp      = " << entity.getHp() << std::endl;
	std::cout << "\tep      = " << entity.getEp() << std::endl;
	std::cout << "\tattack  = " << entity.getAttack() << std::endl;
	std::cout << "ScavTrap stats:" << std::endl;
	std::cout << "\tname    = " << entity2.getName() << std::endl;
	std::cout << "\thp      = " << entity2.getHp() << std::endl;
	std::cout << "\tep      = " << entity2.getEp() << std::endl;
	std::cout << "\tattack  = " << entity2.getAttack() << std::endl;

	// Attack
	entity.attack("Jean");
	entity2.attack("Jack");
	
	return (0);
}
