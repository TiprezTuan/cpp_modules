/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:39 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/12 15:49:15 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Cat::Cat()
	: AAnimal("Cat"), _brain(new Brain)
	{std::cout << "Cat constructor called" << std::endl;}

Cat::Cat(const Cat& other) 
	: AAnimal(other._type), _brain(new Brain(*other._brain))
	{std::cout << "Cat copy constructor called" << std::endl;}

Cat::~Cat() {std::cout << "Cat destructor called" << std::endl; delete _brain;}

/************************************/
/*				Operator			*/
/************************************/
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment called" << std::endl;
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
Brain*	Cat::getBrain(void)	{return _brain;}

/************************************/
/*			Member Functions		*/
/************************************/
void	Cat::makeSound(void) const	{std::cout << "Miaou" << std::endl;}