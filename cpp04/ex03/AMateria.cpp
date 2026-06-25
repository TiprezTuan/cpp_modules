/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:19:16 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/25 16:43:16 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
AMateria::AMateria()
	: _type("")
	{}

AMateria::AMateria(const std::string& type)
	: _type(type)
	{}

AMateria::AMateria(const AMateria& other)
	: _type(other._type)
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
const std::string& AMateria::getType(void) const		{return _type;}

/************************************/
/*			Member Functions		*/
/************************************/
void	AMateria::use(ICharacter&)	{};