/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 02:32:49 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:59:11 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Weapon.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Weapon::Weapon(void)
	: _type("") {}

Weapon::Weapon(std::string type)
	: _type(type) {}

Weapon::~Weapon(void) {}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string Weapon::getType(void)				{return _type;}
void		Weapon::setType(std::string type)	{_type = type;}

/************************************/
/*				Methodes			*/
/************************************/
