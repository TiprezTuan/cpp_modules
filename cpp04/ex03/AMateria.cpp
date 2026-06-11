/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:19:16 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 16:56:06 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
AMateria::AMateria()
	: type("")
	{}

AMateria::AMateria(const std::string& type)
	: type(type)
	{}

AMateria::AMateria(const AMateria& other)
	: type(other.type)
	{}

AMateria::~AMateria()
	{}


/************************************/
/*				Operators			*/
/************************************/
AMateria& AMateria::operator=(const AMateria&)	{return *this;}

/************************************/
/*			Getters / Setters		*/
/************************************/
const std::string& AMateria::getType(void) const		{return type;}

/************************************/
/*			Member Functions		*/
/************************************/
void	AMateria::use(ICharacter&)	{};