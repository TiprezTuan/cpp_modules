/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:46:40 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/05 15:26:21 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Harl::Harl(void) {}
Harl::~Harl(void) {}

/************************************/
/*			Getters / Setters		*/
/************************************/

/************************************/
/*				Methodes			*/
/************************************/
void	Harl::complain(std::string level)
{
	// Tableau de tout les levels possibles
	std::string levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	// Tableau de pointeurs sur fonctions
	void	(Harl::*functions[4])(void) =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	for (int i = 0; i < 4; i++)
		if (level == levels[i])
		{
			(this->*functions[i])();
			break ;
		}
}

void	Harl::_debug(void)
{
	std::cout	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!"
				<< std::endl;
}

void	Harl::_info(void)
{
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years, whereas you started"
				<< " working here just last month."
				<< std::endl;
}

void	Harl::_error(void)
{
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}