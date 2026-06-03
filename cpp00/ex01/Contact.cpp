/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:59:31 by ttiprez           #+#    #+#             */
/*   Updated: 2026/06/03 16:12:26 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

/************************************/
/*		Special Member Functions	*/
/************************************/
Contact::Contact() 
	: _firstName(""), _lastName(""), _nickName(""), _num(""), _darkestSecret("") {}
Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string num, std::string darkestSecret)
	: _firstName(firstName), _lastName(lastName), _nickName(nickName), _num(num), _darkestSecret(darkestSecret) {}
Contact::~Contact() {}

/************************************/
/*			Getters / Setters		*/
/************************************/
std::string Contact::getFirstName()		{return _firstName;}
std::string Contact::getLastName()		{return _lastName;}
std::string Contact::getNickName()		{return _nickName;}
std::string	Contact::getNum()			{return _num;}
std::string Contact::getDarkestSecret()	{return _darkestSecret;}

/************************************/
/*				Methodes			*/
/************************************/
void Contact::display()
{
	std::cout << "_firstName: " << _firstName << "\n";
	std::cout << "LastName: " << _lastName << "\n";
	std::cout << "NickName: " << _nickName << "\n";
	std::cout << "PhoneNumber: " << _num << "\n";
	std::cout << "DarkestSecret: " << _darkestSecret << "\n";
}

