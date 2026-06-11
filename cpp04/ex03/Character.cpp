/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:25:04 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:56:03 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Character::Character()	: _name("Unknown")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name)	: _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)	: _name(other._name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i]) delete _inventory[i];
}

/************************************/
/*				Operators			*/
/************************************/
Character& Character::operator=(const Character& other)
{
	if (this != &other)
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
		}
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
const std::string& Character::getName(void) const	{return _name;}

/************************************/
/*			Member Functions		*/
/************************************/
void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
}
void	Character::unequip(int idx)
{
	if (idx >=0 && idx < 4)
		_inventory[idx] = NULL;
}
void	Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
}