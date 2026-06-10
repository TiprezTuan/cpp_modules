/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:41 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:53:33 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Dog::Dog()
	: Animal("Dog")
	{}
Dog::Dog(const Dog& other) 
	: Animal(other._type) 
	{}
Dog::~Dog() {}

/************************************/
/*				Operator			*/
/************************************/
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/

/************************************/
/*			Member Functions		*/
/************************************/
void	Dog::makeSound(void) const	{std::cout << "Ouaf" << std::endl;}

