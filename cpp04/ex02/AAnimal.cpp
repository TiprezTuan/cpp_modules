/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:06:31 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
AAnimal::AAnimal()
	: _type("Unknown")
	{std::cout << "AAnimal constructor called" << std::endl;}

AAnimal::AAnimal(std::string type)
	: _type(type)
	{std::cout << "AAnimal constructor called" << std::endl;}

AAnimal::AAnimal(const AAnimal& other)
	{_type = other._type; std::cout << "AAnimal copy constructor called" << std::endl;}

AAnimal::~AAnimal() 
	{std::cout << "AAnimal destructor called" << std::endl;}

/************************************/
/*				Operator			*/
/************************************/
AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string	AAnimal::getType(void) const	{return _type;}

/************************************/
/*			Member Functions		*/
/************************************/
void	AAnimal::makeSound(void) const	{std::cout << std::endl;}