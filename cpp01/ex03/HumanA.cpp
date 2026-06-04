/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:35:02 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:52:27 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
HumanA::HumanA(void)
	: _name(""), _weapon(Weapon("")) {}

HumanA::HumanA(std::string name, Weapon weapon)
	: _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

/************************************/
/*			Getters / Setters		*/
/************************************/


/************************************/
/*				Methodes			*/
/************************************/
void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl; 
}