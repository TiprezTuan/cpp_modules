/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:13 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 19:03:56 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

/************************************/
/*		Special Member Functions	*/
/************************************/
PhoneBook::PhoneBook(void) {};
PhoneBook::~PhoneBook(void) {};

/************************************/
/*			Getters / Setters		*/
/************************************/
Contact	PhoneBook::getContact(int id)
{
	for (int i = 0; i < 8; i++)
		if (_contact_tab[i].getId() == id)
			return (_contact_tab[i]);
	return (Contact());
}

/************************************/
/*				Methodes			*/
/************************************/

std::string	PhoneBook::_formatField(std::string str, int width)
{
	if (str.length() > 10)
		str = str.substr(0, width - 1) + ".";
	return (str);
}

void	PhoneBook::display(void)
{
	// id | firstName | lastName | nickName
	std::cout	<< std::right << std::setw(10) << "id" << "|"
				<< std::right << std::setw(10) << "first name" << "|"
				<< std::right << std::setw(10) << "last name" << "|"
				<< std::right << std::setw(10) << "nickname" << "|"
				<< std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (_contact_tab[i].getNum().compare(""))
		{
			std::cout	<< std::right << std::setw(10) << _contact_tab[i].getId() << "|"
						<< std::right << std::setw(10) << _formatField(_contact_tab[i].getFirstName(), 10) << "|"
						<< std::right << std::setw(10) << _formatField(_contact_tab[i].getLastName(), 10) << "|"
						<< std::right << std::setw(10) << _formatField(_contact_tab[i].getNickName(), 10) << "|"
						<< std::endl;
		}
	}
}

int	PhoneBook::length(void)
{
	return (_contact_tab[0].getNbContact() > 7 ? 7 : _contact_tab[0].getNbContact() - 1);
}

void	PhoneBook::addContact(Contact contact)
{
	_contact_tab[(_contact_tab[0].getNbContact() - 1) % 8] = contact;
}