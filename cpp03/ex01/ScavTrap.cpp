/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:25:40 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/25 16:05:27 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/************************************/
/*		Special Member Functions	*/
/************************************/
ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_attack = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
	{std::cout << "ScavTrap copy constructor called" << std::endl;}

ScavTrap::~ScavTrap()	{std::cout << "ScavTrap destructor called" << std::endl;}

/************************************/
/*				Operators			*/
/************************************/
// Copy assignment operator
ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		std::cout << "ScavTrap copy assignment operator called" << std::endl;
		ClapTrap::operator=(other);
	}
	return (*this);
}

/************************************/
/*			Member Functions		*/
/************************************/
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEp() > 0)
	{
		std::cout 
			<< "ScavTrap " << getName() << " attacks " << target 
			<< ", causing " << getAttack() << " points of damage !"
			<< std::endl;
		_ep -= 1;
	}
	else
		std::cout << "ScavTrap doesn't have enough energy to attack." << std::endl;
}