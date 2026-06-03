/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:13 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 16:04:19 by ttiprez          ###   ########.fr       */
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
PhoneBook::PhoneBook() {};
PhoneBook::~PhoneBook() {};

/************************************/
/*			Getters / Setters		*/
/************************************/
Contact	PhoneBook::getContact(int i)	{return contact_tab[i];}

/************************************/
/*				Methodes			*/
/************************************/

std::string PhoneBook::intToString(int n)
{
	std::ostringstream	oss;
	oss << n;
	return (oss.str());
}

std::string	PhoneBook::formatField(std::string str, int width)
{
	if (str.length() > 10)
		str = str.substr(0, width - 1) + ".";
	return (str);
}

void	PhoneBook::display()
{
	// id | firstName | lastName | nickName
	std::cout	<< std::right << std::setw(10) << "id" << "|"
				<< std::right << std::setw(10) << "first name" << "|"
				<< std::right << std::setw(10) << "last name" << "|"
				<< std::right << std::setw(10) << "nickname" << "|"
				<< std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contact_tab[i].getNum().compare(""))
		{
			std::cout	<< std::right << std::setw(10) << intToString(i) << "|"
						<< std::right << std::setw(10) << formatField(contact_tab[i].getFirstName(), 10) << "|"
						<< std::right << std::setw(10) << formatField(contact_tab[i].getLastName(), 10) << "|"
						<< std::right << std::setw(10) << formatField(contact_tab[i].getNickName(), 10) << "|"
						<< std::endl;
		}
	}
}

int	PhoneBook::length()
{
	int	i = 0;
	for (i = 0; i < 8; i++)
		if (!contact_tab[i].getNum().compare(""))
			return (i - 1);
	return (i);
}

void	PhoneBook::addContact(Contact contact)
{
	for (int i = 0; i < 8; i++)
		if (!contact_tab[i].getNum().compare(""))
		{
			contact_tab[i] = contact;
			break;
		}
}