/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:52:33 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 13:18:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
ClapTrap::ClapTrap(std::string name)	
	: _name(name), _hp(10), _ep(10), _attack(0)
	{std::cout << "Constructor called" << std::endl;}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_name	= other._name;
	_hp	= other._hp;
	_ep	= other._ep;
	_attack	= other._attack;
}

ClapTrap::~ClapTrap()	{std::cout << "Destructor called" << std::endl;}

/************************************/
/*				Operators			*/
/************************************/
// Copy assignment operator
ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name	= other._name;
		_hp	= other._hp;
		_ep	= other._ep;
		_attack	= other._attack;
	}
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/

/************************************/
/*			Member Functions		*/
/************************************/
void	ClapTrap::attack(const std::string& target)
{
	if (_ep > 0)
	{
		std::cout 
			<< "Claptrap " << _name << " attacks " << target 
			<< ", causing " << _attack << " points of damage !"
			<< std::endl;
		_ep--;
	}
	else
		std::cout << "Claptrap doesn't have enough energy to attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout 
		<< "Claptrap " << _name << " takes " << amount << " damages."
		<< std::endl;
	_hp -= amount;
	if (_hp <= 0)
		std::cout << "ClapTrap died !!!" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0)
	{
		std::cout 
			<< "Claptrap " << _name << " repaired " << amount << " hp."
			<< std::endl;
		_ep--;
		_hp--;
	}
	else
		std::cout << "Claptrap doesn't have enough energy to attack." << std::endl;
}