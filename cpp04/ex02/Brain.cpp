/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:53:07 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/11 14:06:32 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
Brain::Brain(void)
	{std::cout << "Brain constructor called" << std::endl;}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain copy assignment called" << std::endl;
}

Brain::~Brain(void) {std::cout << "Brain destructor called" << std::endl;}

/************************************/
/*				Operator			*/
/************************************/
Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

/************************************/
/*			Getters / Setters		*/
/************************************/

/************************************/
/*			Member Functions		*/
/************************************/