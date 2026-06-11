/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:55:56 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Ice::Ice()
	: AMateria("ice")
	{}

Ice::Ice(const Ice& other)
	: AMateria(other.type)
	{}

Ice::~Ice()
	{}

/************************************/
/*				Operators			*/
/************************************/
Ice& Ice::operator=(const Ice&)	{return *this;}

/************************************/
/*			Member Functions		*/
/************************************/
AMateria*	Ice::clone() const		{return new Ice(*this);}

void	Ice::use(ICharacter& target)
	{std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;}