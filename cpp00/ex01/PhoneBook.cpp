/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 19:40:13 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 13:16:16 by ttiprez          ###   ########.fr       */
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

/************************************/
/*				Methodes			*/
/************************************/

std::string intToString(int n)
{
	std::ostringstream	oss;
	oss << n;
	return (oss.str());
}

std::string	PhoneBook::center(std::string str, int width)
{
	if ((int)str.length() >= width)
		str = str.substr(0, width);

	int	totalPadding = width - str.length();
	int	paddingLeft = totalPadding / 2;
	int	paddingRight = totalPadding - paddingLeft;

	return (std::string(paddingLeft, ' ') + str + std::string(paddingRight, ' '));
}

void	PhoneBook::display()
{
	// id | firstName | lastName | nickName
	std::cout	<< center("id", 10) << "|"
				<< center("firstName", 10) << "|"
				<< center("lastName", 10) << "|"
				<< center("nickName", 10) << "|";
	for (int i = 0; i < 8; i++)
	{
		if (contact_tab[i].getNum().compare(""))
		{
			std::cout	<< center(intToString(i), 10) << "|"
						<< center(contact_tab[i].getFirstName(), 10) << "|"
						<< center(contact_tab[i].getLastName(), 10) << "|"
						<< center(contact_tab[i].getNickName(), 10) << "|";
		}
	}
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