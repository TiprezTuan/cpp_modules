/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:10:46 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 18:13:08 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Animal::Animal()
	: _type("Unknown")
	{std::cout << "Animal constructor called" << std::endl;}

Animal::Animal(std::string type)
	: _type(type)
	{std::cout << "Animal constructor called" << std::endl;}

Animal::Animal(const Animal& other)
	{_type = other._type; std::cout << "Animal copy constructor called" << std::endl;}

Animal::~Animal() 
	{std::cout << "Animal destructor called" << std::endl;}

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