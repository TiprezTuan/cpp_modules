/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:41 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/12 15:49:06 by ttiprez          ###   ########.fr       */
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
	: AAnimal(other._type), _brain(new Brain(*other._brain))
	{std::cout << "Dog copy constructor called" << std::endl;}

Dog::~Dog() {std::cout << "Dog destructor called" << std::endl; delete _brain;}

/************************************/
/*				Operator			*/
/************************************/
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		delete _brain;
		new Brain(*other._brain);
	}
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/
Brain*	Dog::getBrain(void)	{return _brain;}

/************************************/
/*			Member Functions		*/
/************************************/
void	Dog::makeSound(void) const	{std::cout << "Ouaf" << std::endl;}

