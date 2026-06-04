/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:35:20 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:56:58 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
HumanB::HumanB(void)
	: _name(""), _weapon()		{}

HumanB::HumanB(std::string name)
	: _name(name), _weapon()	{}

HumanB::~HumanB(void) {}

/************************************/
/*			Getters / Setters		*/
/************************************/
void	HumanB::setWeapon(Weapon weapon) {_weapon = weapon;}

/************************************/
/*				Methodes			*/
/************************************/
void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl; 
}