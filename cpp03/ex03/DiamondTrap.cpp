/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:19:16 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 14:30:16 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

/************************************/
/*		Special Member Functions	*/
/************************************/
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("Unknown") {}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	ClapTrap::setHp(FragTrap::getHp());
	ClapTrap::setEp(ScavTrap::getEp());
	ClapTrap::setAttack(FragTrap::getAttack());
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other._name + "_clap_name"), ScavTrap(other), FragTrap(other), _name(other._name)
	{std::cout << "DiamondTrap copy constructor called" << std::endl;}

DiamondTrap::~DiamondTrap()	{std::cout << "DiamondTrap destructor called" << std::endl;}

/************************************/
/*				Operators			*/
/************************************/
// Copy assignment operator
DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	DiamondTrap::getName(void)	{return DiamondTrap::_name;}

/************************************/
/*			Member Functions		*/
/************************************/
void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap::name = " << DiamondTrap::_name << std::endl;
	std::cout << "ClapTrap::name = " << ClapTrap::getName() << std::endl;
}