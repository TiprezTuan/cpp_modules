/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:39 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:05:06 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Cat::Cat()
	: Animal("Cat"), _brain(new Brain)
	{std::cout << "Cat constructor called" << std::endl;}

Cat::Cat(const Cat& other) 
	: Animal(other._type), _brain(other._brain)
	{std::cout << "Cat copy constructor called" << std::endl;}

Cat::~Cat() {std::cout << "Cat destructor called" << std::endl; delete _brain;}

/************************************/
/*				Operator			*/
/************************************/
Cat& Cat::operator=(const Cat& other)
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
void	Cat::makeSound(void) const	{std::cout << "Miaou" << std::endl;}