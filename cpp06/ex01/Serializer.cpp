/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:28:15 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/30 15:49:02 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>
#include <string>
#include <iostream>

/************************************/
/*      Special Member Functions    */
/************************************/
Serializer::Serializer()	{}
Serializer::Serializer(const Serializer& other)	
	{(void) other;}
Serializer::~Serializer()	{}

/************************************/
/*              Operator            */
/************************************/
Serializer& Serializer::operator=(const Serializer& other)
	{(void) other; return (*this);}

/********************************/
/*      Member Functions        */
/********************************/
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}