/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:26:39 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/10 16:55:23 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
	{}
WrongCat::WrongCat(const WrongCat& other) 
	: WrongAnimal(other._type)	
	{}
WrongCat::~WrongCat() {}

/************************************/
/*				Operator			*/
/************************************/
WrongCat& WrongCat::operator=(const WrongCat& other)
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
void	WrongCat::makeSound(void) const	{std::cout << "Miaou" << std::endl;}