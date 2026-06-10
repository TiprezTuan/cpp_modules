/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:52:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 15:03:28 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "----------- Constructor -----------"			<< std::endl;
	ClapTrap	entity("Pierre");
	ScavTrap	entity2("Paul");
	FragTrap	entity3("Jack");
	DiamondTrap	entity4("DIAMOND");

	// Affichage stats
	std::cout << "\n----------- Stats -----------"				<< std::endl;
	std::cout << "Claptrap stats:"							<< std::endl;
	std::cout << "\tname    = " << entity.getName()				<< std::endl;
	std::cout << "\thp      = " << entity.getHp()				<< std::endl;
	std::cout << "\tep      = " << entity.getEp()				<< std::endl;
	std::cout << "\tattack  = " << entity.getAttack()			<< std::endl;
	std::cout << "\nScavTrap stats:"							<< std::endl;
	std::cout << "\tname    = " << entity2.getName()			<< std::endl;
	std::cout << "\thp      = " << entity2.getHp()				<< std::endl;
	std::cout << "\tep      = " << entity2.getEp()				<< std::endl;
	std::cout << "\tattack  = " << entity2.getAttack()			<< std::endl;
	std::cout << "\nFragTrap stats:"							<< std::endl;
	std::cout << "\tname    = " << entity3.getName()			<< std::endl;
	std::cout << "\thp      = " << entity3.getHp()				<< std::endl;
	std::cout << "\tep      = " << entity3.getEp()				<< std::endl;
	std::cout << "\tattack  = " << entity3.getAttack()			<< std::endl;
	std::cout << "\nDiamondTrap stats:"							<< std::endl;
	std::cout << "\tname    = " << entity4.getName()			<< std::endl;
	std::cout << "\thp      = " << entity4.getHp()				<< std::endl;
	std::cout << "\tep      = " << entity4.getEp()				<< std::endl;
	std::cout << "\tattack  = " << entity4.getAttack()			<< std::endl;


	// Attack
	std::cout << "\n----------- Attack() -----------"			<< std::endl;
	entity.attack("Paul");
	entity2.attack("Jack");
	entity3.attack("DIAMOND");
	entity4.attack("Pierre");

	// Special ability
	std::cout << "\n----------- Special ability() -----------"	<< std::endl;
	entity2.guardGate();
	entity3.highFivesGuys();
	entity4.whoAmI();

	std::cout << "\n----------- Destructor -----------"			<< std::endl;
	
	return (0);
}
