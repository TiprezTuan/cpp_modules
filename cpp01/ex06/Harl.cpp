/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:46:40 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/05 15:49:48 by ttiprez          ###   ########.fr       */
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

	int	i = 0;
	for (i = 0; i < 4; i++)
		if (level == levels[i]) {break;}

	switch (i)
	{
	case (0):
		_debug();
		// fall through
	case 1:
		_info();
		// fall through
	case 2:
		_warning();
		// fall through
	case 3:
		_error();
		break;
	default:
		std::cout	<< "[ Probably complaining about insignificant problems ]"
					<< std::endl;
		break ;
	}
}

void	Harl::_debug(void)
{
	std::cout	<<"[DEBUG]" << std::endl;
	std::cout	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				<< "I really do!"
				<< std::endl << std::endl;
}

void	Harl::_info(void)
{
	std::cout	<<"[INFO]" << std::endl;
	std::cout	<< "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!"
				<< std::endl << std::endl;
}

void	Harl::_warning(void)
{
	std::cout	<<"[WARNING]" << std::endl;
	std::cout	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years, whereas you started"
				<< " working here just last month."
				<< std::endl << std::endl;
}

void	Harl::_error(void)
{
	std::cout	<<"[ERROR]" << std::endl;
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl << std::endl;
}