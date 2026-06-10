/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:52:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 14:28:28 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
	ClapTrap	entity("Pierre");
	ScavTrap	entity2("Paul");
	FragTrap	entity3("Jack");

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
	std::cout << "FragTrap stats:" << std::endl;
	std::cout << "\tname    = " << entity3.getName() << std::endl;
	std::cout << "\thp      = " << entity3.getHp() << std::endl;
	std::cout << "\tep      = " << entity3.getEp() << std::endl;
	std::cout << "\tattack  = " << entity3.getAttack() << std::endl;

	// Attack
	entity.attack("Paul");
	entity2.attack("Jack");
	entity3.attack("Pierre");

	// Special ability
	entity2.guardGate();
	entity3.highFivesGuys();
	
	return (0);
}
