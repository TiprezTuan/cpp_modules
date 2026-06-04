/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:20:54 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/04 02:11:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Zombie::Zombie(void)
	: _name("") {}

Zombie::Zombie(std::string name)
	: _name(name) {}

Zombie::~Zombie(void) {std::cout << _name << std::endl;}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	Zombie::getName(void) {return _name;}
void		Zombie::setName(std::string name) {_name = name;}

/************************************/
/*				Methodes			*/
/************************************/
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}