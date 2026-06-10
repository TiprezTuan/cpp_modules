/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 17:48:29 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Animal::Animal() : _type("Unknown") {}
Animal::Animal(std::string type) : _type(type) {}
Animal::Animal(const Animal& other) {_type = other._type;}
Animal::~Animal() {}

/************************************/
/*				Operator			*/
/************************************/
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	Animal::getType(void) const	{return _type;}

/************************************/
/*			Member Functions		*/
/************************************/
void	Animal::makeSound(void) const	{std::cout << std::endl;}