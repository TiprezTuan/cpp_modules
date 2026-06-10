/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:19:16 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:17:24 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/************************************/
/*		Special Member Functions	*/
/************************************/
FragTrap::FragTrap() : ClapTrap() {}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	setHp(100);
	setEp(100);
	setAttack(30);
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
	{std::cout << "FragTrap copy constructor called" << std::endl;}

FragTrap::~FragTrap()	{std::cout << "FragTrap destructor called" << std::endl;}

/************************************/
/*				Operators			*/
/************************************/
// Copy assignment operator
FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

/************************************/
/*			Member Functions		*/
/************************************/
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap high fives !" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (getEp() > 0)
	{
		std::cout 
			<< "FragTrap " << getName() << " attacks " << target 
			<< ", causing " << getAttack() << " points of damage !"
			<< std::endl;
		setEp(getEp() - 1);
	}
	else
		std::cout << "FragTrap doesn't have enough energy to attack." << std::endl;
}