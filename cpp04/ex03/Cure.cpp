/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:41 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:55:56 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Cure::Cure()
	: AMateria("cure")
	{}

Cure::Cure(const Cure& other)
	: AMateria(other.type)
	{}

Cure::~Cure()
	{}

/************************************/
/*				Operators			*/
/************************************/
Cure& Cure::operator=(const Cure&)	{return *this;}

/************************************/
/*			Member Functions		*/
/************************************/
AMateria*	Cure::clone() const		{return new Cure(*this);}

void	Cure::use(ICharacter& target)
	{std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;}

