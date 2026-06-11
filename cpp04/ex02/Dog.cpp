/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:41 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:15:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Dog::Dog()
	: AAnimal("Dog"), _brain(new Brain)
	{std::cout << "Dog constructor called" << std::endl;}

Dog::Dog(const Dog& other) 
	: AAnimal(other._type), _brain(other._brain)
	{std::cout << "Dog copy constructor called" << std::endl;}

Dog::~Dog() {delete _brain; std::cout << "Dog destructor called" << std::endl;}

/************************************/
/*				Operator			*/
/************************************/
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		_type = other._type;
		_brain = other._brain;
	}
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/

/************************************/
/*			Member Functions		*/
/************************************/
void	Dog::makeSound(void) const	{std::cout << "Ouaf" << std::endl;}

