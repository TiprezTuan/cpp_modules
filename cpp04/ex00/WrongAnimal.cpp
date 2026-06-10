/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:55:54 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
WrongAnimal::WrongAnimal() : _type("Unknown") {}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {_type = other._type;}
WrongAnimal::~WrongAnimal() {}

/************************************/
/*				Operator			*/
/************************************/
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	WrongAnimal::getType(void) const	{return _type;}

/************************************/
/*			Member Functions		*/
/************************************/
void	WrongAnimal::makeSound(void) const	{std::cout << std::endl;}