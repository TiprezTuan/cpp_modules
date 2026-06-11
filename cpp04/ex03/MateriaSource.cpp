/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:22:23 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 17:02:06 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		stock[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		stock[i] = other.stock[i] ? other.stock[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (stock[i]) 
			delete stock[i];
}

/************************************/
/*				Operators			*/
/************************************/
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
		for (int i = 0; i < 4; i++)
		{
			delete stock[i];
			stock[i] = other.stock[i] ? other.stock[i]->clone() : NULL;
		}
	return (*this);
}

/************************************/
/*			Member Functions		*/
/************************************/
void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (!stock[i])
		{
			stock[i] = m;
			return ;
		}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (stock[i] && !type.compare(stock[i]->getType()))
			return (stock[i]->clone());
	return (NULL);
}