/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:59:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 18:53:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

/************************************/
/*			Static Variables		*/
/************************************/
int	Contact::_nbContact = 0;

/************************************/
/*		Special Member Functions	*/
/************************************/
Contact::Contact(void) 
	: _contactId(-1), _firstName(""), _lastName(""), _nickName(""), _num(""), _darkestSecret("") {}
Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string num, std::string darkestSecret)
	: _contactId(_nbContact), _firstName(firstName), _lastName(lastName), _nickName(nickName), _num(num), _darkestSecret(darkestSecret) {_nbContact++;}
Contact::~Contact(void) {}

/************************************/
/*			Getters / Setters		*/
/************************************/
int			Contact::getNbContact(void)		{return _nbContact;}
int			Contact::getId(void)			{return _contactId;}
std::string Contact::getFirstName(void)		{return _firstName;}
std::string Contact::getLastName(void)		{return _lastName;}
std::string Contact::getNickName(void)		{return _nickName;}
std::string	Contact::getNum(void)			{return _num;}
std::string Contact::getDarkestSecret(void)	{return _darkestSecret;}

/************************************/
/*				Methodes			*/
/************************************/
void Contact::display(void)
{
	std::cout << "_firstName: " << _firstName << "\n";
	std::cout << "LastName: " << _lastName << "\n";
	std::cout << "NickName: " << _nickName << "\n";
	std::cout << "PhoneNumber: " << _num << "\n";
	std::cout << "DarkestSecret: " << _darkestSecret << "\n";
}

